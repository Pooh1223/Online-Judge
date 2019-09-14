#include <bits/stdc++.h>
using namespace std;
int p[50003];
int sz[50003];
int g[10003][10003];
int gp = 0;
vector<pair<int,int> > v;
map<pair<int,int>,int> mp;
int n,m,t;
void init(){
	for(int i = 0;i < 50003;++i){
		p[i] = i;
		sz[i] = 1;
	}
}
int find(int x){
	return p[x] == x ? x : p[x] = find(p[x]);
}
void _union(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	gp--;
	if(sz[x] > sz[y]){
		p[y] = x;
		sz[x] += sz[y];
	} else {
		p[x] = y;
		sz[y] += sz[x];
	}
}
int check(int x,int y){
	int xl = x - 2 >= 1 ? x - 2 : 1;
	int xr = x + 2 > n ? n : x + 2;
	int yl = y - 2 >= 1 ? y - 2 : 1;
	int yr = y + 2 > m ? m : y + 2;
	for(int i = xl;i <= xr;++i){
		for(int j = yl;j <= yr;++j){
			if(g[i][j] == 1 && !(x == i && y == j)){
				_union(mp[make_pair(i,j)],mp[make_pair(x,y)]);
			}
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	init();
	cin >> n >> m >> t;
	gp = t;
	for(int i = 0;i < t;++i){
		int a,b;
		cin >> a >> b;
		g[a][b] = 1;
		v.push_back(make_pair(a,b));
		mp.insert( make_pair( make_pair(a,b) ,i + 1) );
	}
	for(int i = 0;i < v.size();++i){
		if(g[v[i].first][v[i].second]){
			check(v[i].first,v[i].second);
		}
	}
	cout << gp << "\n";
	return 0;
}