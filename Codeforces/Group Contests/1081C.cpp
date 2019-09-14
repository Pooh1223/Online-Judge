#include <bits/stdc++.h>
using namespace std;

const long long MaxN = 998244353;

long long c[2003][2003]; //c[up][down]

long long power(int p,int k){ // compute p ^ k
	long long ans = 1;
	long long b = p;
	while(k){
		if(k & 1){ // odd
			ans *= b;
			ans %= MaxN;
		}
		b *= b;
		b %= MaxN;
		k >>= 1;
	}
	return ans % MaxN;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long n,m,k;
	cin >> n >> m >> k;
	for(int i = 0;i < 2003;++i){
		c[i][0] = 1;
		if(i) c[i][1] = i;
	}
	for(int i = 1;i < 2003;++i){
		for(int j = 1;j < 2003;++j){
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MaxN;
		}
	}
	//cout << c[n - 1][k] << " * " << m << " * " << power(m,k - 1) << "\n";
	if(!k) cout << m << "\n";
	else if(m == 1) cout << 0 << "\n";
	else cout << (((c[n - 1][k] * m) % MaxN) * (power(m - 1,k)) % MaxN) % MaxN << "\n";
	
	return 0;
}