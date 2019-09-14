#include <bits/stdc++.h>
using namespace std;
int num[101];
vector<int> v;
int main(){
	int n;
	cin >> n;
	for(int i = 0;i < 2 * n;++i) cin >> num[i];
	int mn = 1e9;
	for(int i = 0;i < 2 * n;++i){
		for(int j = 0;j < 2 * n;++j){
			if(i != j){
				v.clear();
				for(int k = 0;k < 2 * n;++k){
					if(k != i && k != j) v.push_back(num[k]);
				}
				sort(v.begin(),v.end());
				int ans = 0;
				for(int k = 0;k < v.size();k += 2){
					ans += v[k + 1] - v[k];
				}
				mn = min(mn,ans);
			}
		}
	}
	cout << mn << "\n";
	return 0;
}