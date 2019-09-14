#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int k,sum = 0;
	cin >> n >> k;
	vector<int> v;
	v.clear();
	for(int i = 0;i < n;++i){
		int j;
		cin >> j;
		v.push_back(j);
	}
	sort(v.begin(),v.end());
	for(int i = 0;i < k;++i) sum += v[i];
	cout << sum << "\n";
	return 0;
}