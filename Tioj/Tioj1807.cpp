#include <bits/stdc++.h>
using namespace std;
set< pair<int,int> > s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n,m,q;
	cin >> n >> m >> q;
	while(m--){
		int a,b;
		cin >> a >> b;
		if(a > b) swap(a,b);
		s.insert(make_pair(a,b));
	}
	while(q--){
		int a,b;
		cin >> a >> b;
		if(a > b) swap(a,b);
		pair<int,int> p(a,b);
		if(s.find(p) != s.end()) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}