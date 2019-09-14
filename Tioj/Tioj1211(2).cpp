#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
//#define ll long long
struct t{
	int m,w;
	bool operator<(const t&a)const{
		return w > a.w;
	}
};
vector< pair<int,int> > g[10005];
bool used[10005];
int d[10005];
int prim(int n,int st){
	int ans = 0;
	memset(used,0,sizeof(used));
	for(int i = 1;i <= n;++i) d[i] = 1e9;
	priority_queue<t> pq;
	d[st] = 0;
	pq.push((t){st,0});
	for(int j = 0;j < n;++j){
		int k = -1;
		while(!pq.empty() && used[k = pq.top().m]) pq.pop();
		ans += pq.top().w;
		if(k == -1) break;
		used[k] = 1;

		for(int i = 0;i < g[k].size();++i){
			int v = g[k][i].first;
			int w = g[k][i].second;
			if(!used[v] && d[v] > w){
				d[v] = w;
				pq.push((t){v,w});
			}
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
		for(int i = 0;i < 10005;++i) g[i].clear();
		for(int i = 0;i < m;++i){
			int a,b,w;
			cin >> a >> b >> w;
			g[a].push_back(make_pair(b,w));
			g[b].push_back(make_pair(a,w));
		}
		if(n - 1 > m) cout << -1 << "\n";
		else{
			int ans = prim(n,1);
			bool ck = 0;
			for(int i = 1;i <= n;++i){
				if(!used[i]) ck = 1;
			}
			if(!ck) cout << ans << "\n";
			else cout << -1 << "\n";
		}
	}
	return 0;
}