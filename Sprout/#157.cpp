#include <iostream>
#include <cstring>
using namespace std;
int w[105],v[105],dp[1000005];
int t,n,m;
int main(){
	cin.tie(0);
	cin >> t;
	while(t--){
		memset(w,0,sizeof(w));
		memset(v,0,sizeof(v));
		memset(dp,0,sizeof(dp));
		cin >> n >> m;
		for(int i = 0;i < n;++i) cin >> w[i] >> v[i];
		for(int i = 0;i < n;++i){
			for(int j = m;j - w[i] >= 0;--j){
				dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
			}
		}
		cout << dp[m] << "\n";
	}
	return 0;
}