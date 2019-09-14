#include <bits/stdc++.h>
using namespace std;

int s1[103];
int s2[103];
int dp[103][103];

int main(){
	int n,m,t = 1;
	while(cin >> n >> m){
		if(!n && !m) break;

		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(dp,0,sizeof(dp));

		for(int i = 1;i <= n;++i) cin >> s1[i];
		for(int i = 1;i <= m;++i) cin >> s2[i];

		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= m;++j){
				if(s1[i] != s2[j]){
					dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
				} else {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
			}
		}

		cout << "Twin Towers #" << t++ << "\n";
		cout << "Number of Tiles : " << dp[n][m] << "\n\n";
	}
	return 0;
}