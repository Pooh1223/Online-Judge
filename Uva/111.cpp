#include <bits/stdc++.h>
using namespace std;

int org[30];
int ask[30];

int main(){
	int n;
	cin >> n;

	for(int i = 1;i <= n;++i){
		int p;
		cin >> p;
		org[p] = i; 
	}
	int jizz;
	while(cin >> jizz){
		memset(ask,0,sizeof(ask));
		ask[jizz] = 1;
		for(int i = 2;i <= n;++i){
			int p;
			cin >> p;
			ask[p] = i;
		}

		int dp[30][30];
		memset(dp,0,sizeof(dp));

		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= n;++j){
				if(org[i] != ask[j]){
					dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
				} else {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
			}
		}

		cout << dp[n][n] << "\n";
	}

	return 0;
}