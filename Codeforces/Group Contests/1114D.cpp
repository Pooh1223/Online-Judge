#include <bits/stdc++.h>
using namespace std;

int color[5003],dp[5003][5003][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0;i < n;++i) cin >> color[i];
	for(int i = 0;i < n;++i){
		for(int j = 0;i + j < n;++j){
			int l = j,r = j + i;
			dp[l][r][0] = min(dp[l + 1][r][0] + (int)(color[l] != color[l + 1])
			 				, dp[l + 1][r][1] + (int)(color[l] != color[r]) );

			dp[l][r][1] = min(dp[l][r - 1][0] + (int)(color[r] != color[l])
							, dp[l][r - 1][1] + (int)(color[r] != color[r - 1]) );
		}
	}

	cout << min(dp[0][n - 1][0],dp[0][n - 1][1]);

	return 0;
}