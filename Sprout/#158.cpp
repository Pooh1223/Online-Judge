#include <iostream>
#include <cstring>
using namespace std;
int w[102],v[102],dp[101][100005];
int t,n,m,k;
int main(){
	cin.tie(0);
	cin >> t;
	while(t--){
		memset(w,0,sizeof(w));
		memset(v,0,sizeof(v));
		memset(dp,0,sizeof(dp));
		cin >> n >> m >> k;
		for(int i = 0;i < n;++i) cin >> w[i] >> v[i];
		for(int i = 0;i < n;++i){
			for(int l = m;l - w[i] >= 0;--l){
				for(int j = 1;j <= k;++j){
					dp[j][l] = max(dp[j][l],dp[j - 1][l - w[i]] + v[i]);
				}
			}
		}
		cout << dp[k][m] << "\n";
	}
	return 0;
}