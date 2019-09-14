#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 0;i < n;++i){
		int j;
		cin >> j;
		while(v.size() > 0 && j >= v.back()){
			v.pop_back();
			if(!v.empty()) ans += min(v.back(),j);
			else ans += j;
		}
		v.push_back(j);
	}
	for(int i = 0;i < v.size() - 1;++i){
		ans += v[i];
	}
	cout << ans << "\n";
	return 0;
}