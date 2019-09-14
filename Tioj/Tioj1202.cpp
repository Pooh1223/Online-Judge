#include <bits/stdc++.h>
using namespace std;
struct t{
	int p,h,in;
	bool operator < (const t&a) const {
		if(p != a.p) return p < a.p;
		if(h != a.h) return h < a.h;
		return in < a.in; 
	}
};
multiset<int, greater<int> > s;
vector<t> v;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	while(cin >> n && n){
		v.clear();
		s.clear();
		while(n--){
			int a,b,c;
			cin >> a >> b >> c;
			v.push_back((t){a,b,1});
			v.push_back((t){c,b,0});
		}
		sort(v.begin(),v.end());
		int q = 0;
		s.insert(0);
		for(int i = 0;i < v.size();){
			int jizz = i;
			while(jizz < v.size() && v[jizz].p == v[i].p){
				if(v[jizz].in == 1) s.insert(v[jizz].h);
				else s.erase(v[jizz].h);
				jizz++;
			}
			if(*s.begin() != q){
				q = *s.begin();
				cout << v[i].p << " " << q << " ";
			}
			i = jizz;
		}
		cout << "\n";
	}
	return 0;
}