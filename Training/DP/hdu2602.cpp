#include <bits/stdc++.h>
using namespace std;

int c[1005],w[1005],dp[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n,v;
		cin >> n >> v;
		memset(dp,0,sizeof(dp));
		for(int i = 0;i < n;++i) cin >> c[i];
		for(int i = 0;i < n;++i) cin >> w[i];
		for(int i = 0;i < n;++i){
			for(int j = v;j >= w[i];--j){
				dp[j] = max(dp[j],dp[j - w[i]] + c[i]);
			}
		}
		cout << dp[v] << "\n";
	}
	
	return 0;
}