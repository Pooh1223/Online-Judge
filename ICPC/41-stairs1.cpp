#include <bits/stdc++.h>
using namespace std;
int sis[105];
int main(){
	int n,x;
	cin >> n >> x;
	if(x >= 2 * n - 1 && x <= n * n){
		int q = x;
		int cnt = 1,now = 1;
		fill(sis,sis + 105,1);
		sis[n] = n;
		x -= (2 * n - 1);
		for(int i = 0;i < x;++i){
			if(sis[cnt] == n) cnt++;
			if(sis[cnt] < n) sis[cnt]++;
		}
		for(int i = 1;i <= q;++i){
			if(sis[now] != 0) cout << 10031 + now << "\n",sis[now]--;
			else now++,--i;
		}
	} else cout << "Impossible\n";
	return 0;
}