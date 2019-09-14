#include <bits/stdc++.h>
using namespace std;
int g[20][20],dp[20][1 << 16];
int path(int n,int s,int len){
	if(dp[n][s]) return dp[n][s];

	int jizz = 1e9;
	for(int i = 0;i < len;++i){
		if((s & (1 << i)) != 0 && i != n){
			jizz = min(jizz,(path(i,s ^ (1 << n),len) + g[i][n]));
		}
	}
	return dp[n][s] = jizz;
}
int main(){
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(g,0,sizeof(g));
		int n;
		cin >> n;
		for(int i = 0;i < n - 1;++i){
			for(int j = i + 1;j < n;++j){
				cin >> g[i][j];
				g[j][i] = g[i][j];
			}
		}
		for(int i = 0;i < n;++i) dp[i][(1 << i)] = g[0][i];

		cout << path(0,(1 << n) - 1,n) << "\n";
	}
	return 0;
}