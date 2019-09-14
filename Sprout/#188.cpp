#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100005],val[100005];
deque<ll> dq;
int main(){
	//ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(val,0,sizeof(val));
		dq.clear();
		ll n,k,c;
		cin >> n >> k >> c;
		ll mx = -1e9;
		for(int i = 1;i <= n;++i) cin >> val[i];
		for(int i = 1;i <= n;i++){
			while(!dq.empty() && dq.front() + k < i) dq.pop_front();
			if(!dq.empty()) dp[i] = max({0LL,val[i],dp[dq.front()] - c * (i - dq.front()) + val[i]});
			else dp[i] = max(0LL,val[i]);
			while(!dq.empty() && dp[i] > dp[dq.back()] - c * (i - dq.back())) dq.pop_back();
			dq.push_back(i);
			mx = max(dp[i],mx);
		}
		for(int i = 0;i < n;i++) cout << "dp[" << i << "] : " << dp[i] << "\n";
		cout << max({dp[dq.front()],0LL,mx}) << "\n";
	}
	return 0;
}