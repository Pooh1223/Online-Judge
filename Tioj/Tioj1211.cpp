#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct t{
	int a,b,w;
	/*bool operator<(const t&k){
		return w < k.w;
	}*/
};
vector<t> g;
int cnt = 0;
bool cmp(const t&a,const t&b){return a.w < b.w;}
int p[10005],sz[10005];
void init(int n){for(int i = 0;i <= n;++i){p[i] = i;sz[i] = 1;}}
int find(int n){return n == p[n] ? n : p[n] = find(p[n]);}
bool single(int n){return sz[p[n]] == 1;}
void _union(int x,int y){
	x = find(x),y = find(y);
	if(x == y) return;
	if(sz[x] < sz[y]){
		p[x] = y;
		sz[y] += sz[x];
	} else {
		p[y] = x;
		sz[x] += sz[y];
	}
}
int kruskal(int n,int m){
	int ans = 0;
	sort(g.begin(),g.end(),cmp);
	/*for(int i = 0,j = 0;i < n - 1 && j < m;++i){
		while(find(g[j].a) == find(g[j].b)) ++j;
		_union(g[j].a,g[j].b);
		ans += g[j].w;
		++j;
	}*/
	for(int i = 0;i < m;++i){
		t q = g[i];
		if(find(q.a) != find(q.b)){
			_union(q.a,q.b);
			ans += q.w;
			++cnt;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		if(n == 0 && m == 0) break;
		cnt = 0;
		g.clear();
		memset(p,0,sizeof(p));
		memset(sz,0,sizeof(sz));
		init(n);
		for(int i = 0;i < m;++i){
			int a,b,w;
			cin >> a >> b >> w;
			g.push_back((t){a,b,w});
		}
		if(n - 1 > m) cout << -1 << "\n";
		else {
			int ans = kruskal(n,m);
			/*bool ck = 0;
			for(int i = 1;i <= n;++i){
				if(single(i)) ck = 1;
			}*/
			if(cnt == n - 1) cout << ans << "\n";
			else cout << -1 << "\n";
		}
	}
	return 0;
}