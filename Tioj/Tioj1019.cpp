#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1005],val[1005];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0;i < n;++i) cin >> val[i];
		dp[0] = 0;
		dp[1] = abs(val[1] - val[0]);
		for(int i = 2;i < n;++i){
			dp[i] = min(dp[i - 1] + abs(val[i] - val[i - 1]),dp[i - 2] + abs(val[i] - val[i - 2]));
		}
		cout << dp[n - 1] << "\n";
	}
	return 0;
}