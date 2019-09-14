#include <bits/stdc++.h>
using namespace std;
vector< pair<int,long long> > g[103];
long long d[103];
bool used[103];
void dijkstra(int n,int u){
	for(int i = 0;i <= n;++i) d[i] = 1e18;
	d[u] = 0;
	for(int k = 0;k < n;++k){
		long long mn = 1e18,ans = -1;
		for(int i = 1;i <= n;++i){
			if(!used[i] && mn > d[i]){
				mn = d[i];
				ans = i;
			}
		}
		if(ans == -1) return;
		used[ans] = 1; 
		for(int i = 0;i < g[ans].size();++i){
			long long v = g[ans][i].first;
			long long w = g[ans][i].second;
			if(!used[v] && d[ans] + w < d[v]) d[v] = d[ans] + w;
		}
	}
}
int main(){
	cin.tie(0);
	long long t;
	cin >> t;
	while(t--){
		long long n,m,s,e,f;
		cin >> n >> m >> s >> e >> f;
		while(m--){
			long long a,b,c,d,cc;
			long long weight;
			cin >> a >> b >> c >> d >> cc;
			if(f > d) weight = (d * c) + (f - d) * cc;
			else weight = f * c;
			g[a].push_back(make_pair(b,weight));
			//g[b].push_back(make_pair(a,weight));
		}
		dijkstra(n,s);
		cout << d[e] << "\n";
		for(int i = 0;i < 103;++i) g[i].clear();
		memset(used,0,sizeof(used));
	}
	return 0;
}