#include <bits/stdc++.h>
using namespace std;
vector<int> g[1000005];
vector<int> bcc[1000005];
int low[1000005],dfn[1000005];
int times = 0;
bool r[1000005];

void dfs(int n,int fa){
	low[n] = dfn[n] = ++times;
	int child = 0;
	for(int i = 0;i < g[n].size();++i){
		int v = g[n][i];
		if(v == fa) continue;
		if(!dfn[v]){
			child++;
			dfs(v,n);
			low[n] = min(low[n],low[v]);
			if(low[v] >= dfn[n]) r[n] = 1;
		} else {
			low[n] = min(low[n],dfn[v]);
		}
	}
	if(dfn[n] == 1 && child <= 1) r[n] = 0;
}

int main(){
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	while(m--){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,1);
	for(int i = 1;i <= n;++i)
		if(r[i]) cout << i << '\n';
	return 0;
}