#include <bits/stdc++.h>
#define N 100003
#define M 300003
using namespace std;
struct node{
	int val,d;
};
vector<int> v[N];
int D,ans = 0,val[N];
bool vis[N];
void dfs(int u,int d,bool used[]){
	if(d > D) return;
	for(int i = 0;i < v[u].size();++i){
		int vx = v[u][i];
		if(!used[vx]){
			used[vx] = 1;
			if(d + 1 <= D) vis[vx] = 1;
			dfs(vx,d + 1,used);
			used[vx] = 0;
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;++i) cin >> val[i];
	while(m--){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin >> D;
	bool used[N] = {};
	used[0] = 1;
	vis[0] = 1;
	dfs(0,0,used);
	for(int i = 0;i < n;++i) if(vis[i]) ans += val[i];
	cout << ans << "\n";
	return 0;
}