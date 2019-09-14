#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool cmp(const int a,const int b){return a < b;}
int main(){
	cin.tie(0);
	int n;
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i = 0;i < v.size();++i){
		if(i == 0) cout << v[i];
		else cout << " " << v[i];
	}
	return 0;
}