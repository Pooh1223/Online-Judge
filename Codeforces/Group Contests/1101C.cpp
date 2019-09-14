#include <bits/stdc++.h>
using namespace std;

struct point{
	int st,ed,id;
};

bool cmp1(point a,point b){
	if(a.st != b.st) return a.st < b.st;
	return a.ed < b.ed;
}

bool cmp2(pair<int,int> a,pair<int,int> b){
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--){
		int jizz;
		bool ck = 0;
		cin >> jizz;
		vector<point> seg;
		vector< pair<int,int> > v;
		for(int i = 0;i < jizz;++i){
			int a,b;
			cin >> a >> b;
			seg.push_back(point{a,b,i});
		}
		sort(seg.begin(),seg.end(),cmp1);
		int oneEd = seg[0].ed,pos;
		v.push_back(pair<int,int>{1,seg[0].id});
		for(int i = 1;i < seg.size();++i){
			if(seg[i].st <= oneEd){ // overlap
				oneEd = max(seg[i].ed,oneEd); // update right boundary
				v.push_back(pair<int,int>{1,seg[i].id});
			} else { // non-intersect 
				v.push_back(pair<int,int>{2,seg[i].id});
				ck = 1;
			}
		}
		sort(v.begin(),v.end(),cmp2);
		if(!ck) cout << -1 << "\n";
		else {
			for(int i = 0;i < v.size();++i) cout << v[i].first << " ";
			cout << "\n";
		}
	}
	return 0;
}