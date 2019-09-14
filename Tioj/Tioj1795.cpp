#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
vector<PII> g[100005];
struct q{
	int m,w;
	bool operator<(const q&a) const{
		return w > a.w;
	}
};
struct qq{
	int m,w;
	bool operator<(const qq&a) const{
		return w < a.w;
	}
};
bool used[100005];
int d[100005];
int n,m,k;
int mn_prim(int st){
	priority_queue<q> pq;
	int ans = 0;
	fill(d,d + 100005,1e9);
	memset(used,0,sizeof(used));
	d[st] = 0;
	pq.push((q){st,0});
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
				pq.push((q){v,w});
			}
		}
	}
	return ans;
}
int mx_prim(int st){
	priority_queue<qq> pq;
	int ans = 0;
	fill(d,d + 100005,-1);
	memset(used,0,sizeof(used));
	d[st] = 1e9;
	pq.push((qq){st,0});
	for(int j = 0;j < n;++j){
		int k = -1;
		while(!pq.empty() && used[k = pq.top().m]) pq.pop();
		ans += pq.top().w;
		if(k == -1) break;
		used[k] = 1;
		for(int i = 0;i < g[k].size();++i){
			int v = g[k][i].first;
			int w = g[k][i].second;
			if(!used[v] && d[v] < w){
				d[v] = w;
				pq.push((qq){v,w});
			}
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0;i < m;++i){
		int a,b,w;
		cin >> a >> b >> w;
		g[a].push_back(make_pair(b,w));
		g[b].push_back(make_pair(a,w));
	}
	if(k >= mn_prim(1) && k <= mx_prim(1)) cout << "TAK\n";
	else cout << "NIE\n";
	return 0;
}