#include <bits/stdc++.h>
using namespace std;

long long dp[35];

int main(){
	long long n,l,u;

	dp[0] = 1;
	for(long long i = 1;i < 35;++i){
		dp[i] = dp[i - 1] * 2;
	}

	while(cin >> n >> l >> u){
		long long ans = 0;

		for(long long i = dp[33];i > 0 && ans <= u;i >>= 1){
			if(i > u) continue;

			if(i - 1 < l){
				ans += i;
				l -= i;
			} else {
				//cout << (i & n) << "\n";
				if((i & n) == 0 && ans + i <= u){
					ans += i;
					l -= i;
					//cout << i << "\n";
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}