#include <bits/stdc++.h>
using namespace std;

vector<long long> prime;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();

	prime.push_back(2);
	for(int i = 3;i <= 31623;i += 2){
		bool ok = 1;
		for(int j = 2;j <= sqrt(i);++j){
			if(!(i % j)){
				ok = 0;
				break;
			}
		}
		if(ok) prime.push_back(i);
	}

	int t;
	cin >> t;
	string ans = "";
	while(t--){
		int mx = -1,num = -1;
		long long l,r;
		cin >> l >> r;
		
		for(long long i = l;i <= r;++i){
			int now = i;
			int pos = 0,cnt = 0,sum = 1;
			while(pos < prime.size() && prime[pos] <= now){
				if(!(now % prime[pos])){
					now /= prime[pos];
					cnt++;
				} else {
					sum *= cnt + 1;
					cnt = 0;
					pos++;
				}
			}
			sum *= cnt + 1;
			if(mx < sum){
				mx = sum;
				num = i;
			}
		}
		
		cout << "Between " << l << " and " << r << ", " << num
		<< " has a maximum of " << mx << " divisors.\n";
	}

	return 0;
}