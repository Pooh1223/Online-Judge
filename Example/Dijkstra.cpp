#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define N 1000005
#define ll long long
bool used[N];
int d[N];
vector< pair<int,int> > g[N];
void dijkstra(int n,int st){
	memset(used,0,sizeof(used));
	for(int i = 0;i < n;++i) d[i] = 1e9;
	d[st] = 0;
	for(int j = 0;j < n;++j){
		ll mn = 1e18,k = -1;
		for(int i = 0;i < n;++i){
			if(!used[i] && mn > d[i]){
				mn = d[i];
				k = i;
			}
		}
		if(k == -1) break;
		used[k] = 1;
		for(int i = 0;i < g[k].size();++i){
			int v = g[k][i].first;
			int w = g[k][i].second;
			if(!used[v] && d[v] > d[k] + w){
				d[v] = d[k] + w;
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