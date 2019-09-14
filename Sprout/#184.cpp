#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int> > g[1000005];
int low[1000005],lv[1000005];
set<int> ss;
pair<int,int> eg[1000005];
void dfs(int u,int fa,int d){
	low[u] = lv[u] = d;
	int child = 0;
	for(int i = 0;i < g[u].size();++i){
		int v = g[u][i].first;
		if(v == fa) continue;
		if(!lv[v]){
			child++;
			dfs(v,u,d + 1);
			low[u] = min(low[u],low[v]);
			if(low[v] > lv[u]){
				ss.insert(g[u][i].second);
			}
		} else {
			low[u] = min(low[u],lv[v]);
		}
	}
}

int main(){
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= m;++i){
		int a,b;
		cin >> a >> b;
		g[a].push_back(make_pair(b,i));
		g[b].push_back(make_pair(a,i));
		eg[i].first = a,eg[i].second = b;
	}
	dfs(1,0,1);
	for(set< int >::iterator i = ss.begin();i != ss.end();i++){
		int val = *i;
		cout << eg[val].first << " " << eg[val].second << "\n";
	}
	return 0;
}