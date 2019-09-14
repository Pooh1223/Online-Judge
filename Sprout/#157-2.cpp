#include <iostream>
#include <cstring>
using namespace std;
int w[105],v[105],dp[10005];
int t,n,m;
int main(){
	cin.tie(0);
	//cout << "yee\n";
	cin >> t;
	while(t--){
		memset(w,0,sizeof(w));
		memset(v,0,sizeof(v));
		for(int i = 0;i < 10005;++i) dp[i] = 1e9;
		cin >> n >> m;
		int sumw = 0,sumv = 0;
		for(int i = 0;i < n;++i) cin >> w[i] >> v[i],sumv += v[i];
		//cout << sumv << "\n";
		dp[0] = 0;
		for(int i = 0;i < n;++i){
			for(int j = sumv;j - v[i] >= 0;--j){
				dp[j] = min(dp[j],dp[j - v[i]] + w[i]);
			}
		}
		int ans = 0;
		for(int i = 0;i <= sumv;++i) if(dp[i] <= m) ans = max(ans,i);
		cout << ans << "\n";
	}
	return 0;
}