#include <bits/stdc++.h>
using namespace std;

int dp[53][53];

int main(){
	int l;
	while(cin >> l){
		if(!l) break;
		
		for(int i = 0;i < 53;++i)
			for(int j = 0;j < 53;++j)
				dp[i][j] = 1e9;

		int n;
		cin >> n;
		int num[53] = {0};
		for(int i = 1;i <= n;++i) cin >> num[i];
		num[n + 1] = l;

		for(int i = 0;i <= n;++i) dp[i][i + 1] = 0;

		for(int len = 2;len <= n + 1;++len){
			for(int i = 0;i + len <= n + 1;++i){
				int j = i + len;
				if(j > n + 1) break;

				for(int k = i;k < j;++k){
					dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j] + num[j] - num[i]);
				}
			}
		}

		cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
	}
	return 0;
}