#include <bits/stdc++.h>
using namespace std;
struct node{
	int w,h;
};
bool cmp_sort(const node&a,const node&b){return a.w == b.w ? a.h > b.h : a.w < b.w ;}
bool cmp_lower(const node&a,const node&b){return a.h < b.h;}
int lis(vector<node> s){
	if(s.size() == 0) return 0;
	vector<node> v;
	v.push_back(s[0]);
	for(int i = 1;i < s.size();++i){
		node u = s[i];
		if(v.back().h < u.h) v.push_back(u);
		else *lower_bound(v.begin(),v.end(),u,cmp_lower) = u;
	}
	return v.size();
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		vector<node> v;
		int n;
		cin >> n;
		while(n--){
			int a,b;
			cin >> a >> b;
			v.push_back((node){a,b});
		}
		sort(v.begin(),v.end(),cmp_sort);
		cout << lis(v) << "\n";
	}
	return 0;
}