#include <bits/stdc++.h>
using namespace std;
deque< pair<int,int> > dq;
int val[100005],dp[100005];
int main(){
	//cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(val,0,sizeof(val));
		dq.clear();
		int n,k,c;
		cin >> n >> k >> c;
		for(int i = 0;i < n;++i) cin >> val[i];
		int mx = -1e9;
		for(int i = 0;i < n;++i){
			while(!dq.empty() && dq.front().second + k < i) dq.pop_front();
			if(i == 0) dp[i] = val[i];
			else dp[i] = max(val[i],val[i] - c * i + dq.front().first);
			while(!dq.empty() && dq.back().first < max(dp[i] + c * i,0) && dq.back().second < i) dq.pop_back();
			if(i != 0) dq.push_back(make_pair(max(dp[i] + c * i,0),i));
			else dq.push_back(make_pair(dp[i],i));
			mx = max(dp[i],mx);
		}
		//cout << "jizzzzzzzz\n";
		//for(int i = 0;i < n;i++) cout << "dp[" << i << "] : " << dp[i] << "\n";
		cout << max(mx,0) << "\n";
	}
	return 0;
}