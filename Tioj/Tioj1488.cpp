#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll dp[1003][1003];
vector<pair<int,int> > v;
ll ans;
ll yee(int l,int r){
	if(dp[l][r] != 0) return dp[l][r];
	if(l == r) return 0;
	ll mn = 1e18;
	for(int i = l;i < r;++i){
		mn = min(mn,yee(l,i) + yee(i + 1,r) + v[l].first * v[i].second * v[r].second);
	}
	return dp[l][r] = mn;
}
int main(){
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(dp,0,sizeof(dp));
		v.clear();
		cin >> n;
		for(int i = 0;i < n;++i){
			int a,b;
			cin >> a >> b;
			v.push_back(make_pair(a,b));
			//if(i - 1 >= 0) dp[i - 1][i] = v[i - 1].first * v[i - 1].second * v[i].second;
		}
		ll jizz = yee(0,n - 1);
		//cout << jizz << "\n";
		cout << (jizz % 1000 == 0 ? jizz / 1000 : (jizz / 1000) + 1) << "\n";
		ans += jizz;
	}
	cout << (ans % 1000 == 0 ? ans / 1000 : (ans / 1000) + 1) << "\n";
	return 0;
}