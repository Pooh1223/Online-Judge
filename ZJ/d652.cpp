#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,num[103];
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
	cin >> n;
	for(int i = 0;i < n;++i){
		cin >> num[i];
	}
	for(int i = 1;i < n;++i){
		v.push_back(make_pair(num[i - 1],num[i]));
	}
	ll jizz = yee(0,n - 2);
	cout << jizz << "\n";
	return 0;
}