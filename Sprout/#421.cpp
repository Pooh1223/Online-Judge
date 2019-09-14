#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int lis(vector<int> s){
	if(s.size() == 0) return 0;
	vector<int> len;
	len.push_back(s[0]);
	for(int i = 1;i < s.size();++i){
		int n = s[i];
		if(n >= len.back()) len.push_back(n);
		else *upper_bound(len.begin(),len.end(),n) = n;
	}
	return len.size();
}
int main(){
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		v.clear();
		int n,m;
		cin >> n >> m;
		for(int i = 0;i < n;++i){
			int num;
			cin >> num;
			if(2 * num >= m) v.push_back(2 * num);
			if(num >= m) v.push_back(num);
		}
		cout << lis(v) << "\n";
	}
	return 0;
}