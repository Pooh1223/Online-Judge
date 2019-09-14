#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool cmp(const int&a,const int&b){return a < b;}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i <= n;++i){
		if(i < n){
			int j;
			cin >> j;
			v.push_back(j);
		} else {
			v.push_back(1e9);
		}
	}
	sort(v.begin(),v.end(),cmp);
	int mn = 1e9 + 7;
	while(m--){
		int q;
		cin >> q;
		int qq = *lower_bound(v.begin(),v.end(),q);
		if(qq == 1e9) mn = min(mn,abs(v[lower_bound(v.begin(),v.end(),q) - v.begin() - 1] - q));
		else mn = min(mn,abs(qq - q));
	}
	cout << mn << "\n";
	return 0;
}