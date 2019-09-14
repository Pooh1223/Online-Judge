#include <bits/stdc++.h>
#include "lib1481.h"
using namespace std;
vector< pair<int,int> > g[5003]; //vertex,edge_id
bool used[100005];
int ans[100005];
int cnt = 1;
void dfs(int u){
	for(int i = 0;i < g[u].size();++i){
		int v = g[u][i].first;
		int e = g[u][i].second;
		if(!used[e]){
			used[e] = 1;
			ans[e] = cnt++;
			dfs(v);
		}
	}
}
int main(){
	Init();
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 0;i < k;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(make_pair(b,i));
		g[b].push_back(make_pair(a,i));
	}
	Possible();
	dfs(1);
	for(int i = 0;i < k;++i) Number(ans[i]);
	Finish();
	return 0;
}