#include <bits/stdc++.h>
using namespace std;
void lis(vector<int> s){
	if(s.size() == 0){
		cout << "0\n-\n";
		return;
	}
	vector<int> v,pos;
	v.push_back(s[0]);
	pos.push_back(0);
	for(int i = 1;i < s.size();++i){
		int u = s[i];
		if(v.back() < u){
			v.push_back(u);
			pos.push_back(v.size() - 1);
		} 
		else {
			*lower_bound(v.begin(),v.end(),u) = u;
			pos.push_back(lower_bound(v.begin(),v.end(),u) - v.begin());
		} 
	}
	cout << v.size() << "\n-\n";
	int q = v.size() - 1;
	vector<int> ans;
	for(int i = pos.size() - 1;i >= 0;--i){
		if(q == pos[i]) ans.push_back(s[i]),q--;
	}
	for(int i = ans.size() - 1;i >= 0;--i){
		cout << ans[i] << "\n";
	}
}
int main(){
	int num;
	vector<int> v;
	while(cin >> num){
		v.push_back(num);
	}
	lis(v);
	return 0;
}