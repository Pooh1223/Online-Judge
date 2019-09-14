#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define N 1000005
struct node{
	int m,w;
	bool operator<(const node&a)const{
		return w > a.w;
	}
};
bool used[N];
int d[N];
vector< pair<int,int> > g[N];
void dijkstra(int n,int st){
	memset(used,0,sizeof(used));
	for(int i = 0;i < n;++i) d[i] = 1e9;
	priority_queue<node> pq;
	d[st] = 0;
	pq.push((node){st,0});
	for(int j = 0;j < n;++j){
		//for(int i = 0;i < n;++i) cout << i << " : " << d[i] << "\n";
		int k = -1;
		while(!pq.empty() && used[k = pq.top().m]){
			//cout << pq.top().m << "\n";
			pq.pop();
		} 

		if(k == -1) break;
		used[k] = 1;

		for(int i = 0;i < g[k].size();++i){
			int v = g[k][i].first;
			int w = g[k][i].second;
			if(!used[v] && d[v] > d[k] + w){
				d[v] = d[k] + w;
				pq.push((node){v,d[v]});
			}
		}
	}
}
int main(){
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	while(q--){
		int a,b,w;
		cin >> a >> b >> w;
		g[a].push_back(make_pair(b,w));
		g[b].push_back(make_pair(a,w));
	}
	dijkstra(n,0);
	for(int i = 0;i < n;++i) cout << i << " : " << d[i] << "\n";
	return 0;
}