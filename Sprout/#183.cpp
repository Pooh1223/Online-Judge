#include <iostream>
#include <vector>
using namespace std;
vector<int> g[1000005];
int low[1000005],lv[1000005];
bool r[1000005];
void dfs(int u,int fa,int d){
	low[u] = lv[u] = d;
	int child = 0;
	for(int i = 0;i < g[u].size();++i){
		int v = g[u][i];
		if(v == fa) continue;
		if(!lv[v]){
			child++;
			dfs(v,u,d + 1);
			low[u] = min(low[u],low[v]);
			if(low[v] >= lv[u]){
				r[u] = 1;
			}
		} else {
			low[u] = min(low[u],lv[v]);
		}
	}
	if(lv[u] == 1 && child <= 1) r[u] = 0;
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
	dfs(1,0,1);
	for(int i = 1;i <= n;++i)
		if(r[i]) cout << i << '\n';
	return 0;
}