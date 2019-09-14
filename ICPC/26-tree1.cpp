#include <bits/stdc++.h>
using namespace std;
int num[2505];
vector<int> g[2505];
bool used[2505],chosen[2505];
int n,m;
int dfs(int u,int id){
	int ans = 0;
	for(int i = 0;i < g[u].size();++i){
		int v = g[u][i];
		if(!used[v] && id < m && g[v].size() == num[id]){
			used[v] = 1;
			ans += dfs(v,id + 1);
		}
	}
	if(id == m) return ++ans;
	else return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n - 1;++i){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 0;i < m;++i) cin >> num[i];
	//for(int i = 1;i <= n;++i) d[i] = g[i].size();
	int ans = 0;
	for(int i = 1;i <= n;++i){
		if(!chosen[i] && num[0] == g[i].size()){
			chosen[i] = 1;
			used[i] = 1;
			ans += dfs(i,1);
			memset(used,0,sizeof(used));
		}
	}
	cout << ans;
	return 0;
}