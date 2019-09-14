#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int> > g[1000005];
int low[1000005],dfn[1000005];
int times = 0;
pair<int,int> eg[1000005];
set<int> ss;
void dfs(int n,int fa){
	low[n] = dfn[n] = ++times;
	int child = 0;
	for(int i = 0;i < g[n].size();++i){
		int v = g[n][i].first;
		if(v == fa) continue;
		if(!dfn[v]){
			child++;
			dfs(v,n);
			low[n] = min(low[n],low[v]);
			if(low[v] > dfn[n]) ss.insert(g[n][i].second);
		} else {
			low[n] = min(low[n],dfn[v]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= m;++i){
		int a,b;
		scanf("%d %d",&a,&b);
		g[a].push_back(make_pair(b,i));
		g[b].push_back(make_pair(a,i));
		eg[i].first = a,eg[i].second = b;
	}
	dfs(1,1);
	for(set< int >::iterator i=ss.begin();i!=ss.end();i++){
		int val = *i;
		cout << eg[val].first << " " << eg[val].second << "\n";
	}
	return 0;
}