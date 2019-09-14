#include <bits/stdc++.h>
using namespace std;

int dp[103][103];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int c;
	cin >> c;
	while(c--){
		int n;
		cin >> n;
		for(int i = 1;i <= n;++i){
			for(int j = 0;j < i;++j){
				cin >> dp[i - 1][j];
			}
		}
		for(int i = 0;i < n;++i){
			for(int j = 0;j <= i;++j){
				dp[i][j] += max(i - 1 >= 0 ? dp[i - 1][j] : 0 , 
								i - 1 >= 0 && j - 1 >= 0 ? dp[i - 1][j - 1] : 0);
			}
		}
		int ans = -1;
		for(int i = 0;i < n;++i) ans = max(dp[n - 1][i],ans);
		cout << ans << "\n";
	}
	
	return 0;
}