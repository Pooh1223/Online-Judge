#include <bits/stdc++.h>
using namespace std;

int c[105],w[105],dp[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n,m,k,s;
	while(cin >> n >> m >> k >> s){
		memset(dp,0,sizeof(dp));
		for(int i = 0;i < k;++i) cin >> c[i] >> w[i];
		for(int i = 0;i < k;++i){
			for(int j = w[i];j <= m;++j){
				for(int k = 1;k <= s;++k){
					dp[j][k] = max(dp[j][k],dp[j - w[i]][k - 1] + c[i]);
				}
			}
		}
		if(dp[m][s] >= n){
			for(int i = 0;i <= m;++i){
				if(dp[i][s] >= n){
					cout << m - i << "\n";
					break;
				} 
			}
		} else cout << "-1\n";
	}

	return 0;
}