#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dg[200005],du[200005];
vector< pair<int,ll> > g[200005];
vector< pair<int,ll> > uu[200005];
bool used[200005],desu[200005];
struct node{int b,d;};
bool operator<(const node& a,const node& b){return a.d > b.d;}
priority_queue<>
void dijkstra(int n,int u){
	for(int i = 1;i <= n;++i) dg[i] = 1e18;
	dg[u] = 0;
	for(int k = 0;k < n;++k){
		int ans = -1;
		ll mn = 1e18;
		for(int i = 1;i <= n;++i){
			if(!used[i] && mn > dg[i]){
				ans = i;
				mn = dg[i];
			}
		}
		if(ans == -1) return;
		used[ans] = 1;
		for(int i = 0;i < g[ans].size();++i){
			int v = g[ans][i].first;
			int w = g[ans][i].second;
			if(!used[v] && dg[v] > dg[ans] + w){
				dg[v] = dg[ans] + w;
			}
		}
	}
}
void artskjid(int n,int u){
	for(int i = 1;i <= n;++i) du[i] = 1e18;
	du[u] = 0;
	for(int k = 0;k < n;++k){
		int ans = -1;
		ll mn = 1e18;
		for(int i = 1;i <= n;++i){
			if(!desu[i] && mn > du[i]){
				ans = i;
				mn = du[i];
			}
		}
		if(ans == -1) return;
		desu[ans] = 1;
		for(int i = 0;i < uu[ans].size();++i){
			int v = uu[ans][i].first;
			int w = uu[ans][i].second;
			if(!desu[v] && du[v] > du[ans] + w){
				du[v] = du[ans] + w;
			}
		}
	}
}
int main(){
	cin.tie(0);
	int n,m,q;
	cin >> n >> m >> q;
	while(m--){
		int a,b;
		ll w;
		cin >> a >> b >> w;
		g[a].push_back(make_pair(b,w));
		uu[b].push_back(make_pair(a,w));
	}
	dijkstra(n,1);
	artskjid(n,n);
	//for(int i = 1;i <= n;++i) printf("dg[%d] : %d\n",i,dg[i]);
	//cout << "\n";
	//for(int i = 1;i <= n;++i) printf("du[%d] : %d\n",i,du[i]);
	//cout << "\n";
	while(q--){
		int a,b;
		cin >> a >> b;
		cout << min(dg[n],dg[a] + 1 + du[b]) << "\n";
	}
	return 0;
}