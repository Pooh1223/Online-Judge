#include <bits/stdc++.h>
using namespace std;

struct node{
	int id,d;
};

vector<int> v[103];
bool used[103];
map<long long,int> mp;

int bfs(int u,int step){
	int tt = 0;

	queue<node> q;
	q.push({u,0});
	used[u] = 1;

	while(!q.empty()){
		node st = q.front();
		q.pop();

		int id = st.id;
		int d = st.d;

		if(d > step) continue;
		tt++;

		for(int i = 0;i < v[id].size();++i){
			if(!used[v[id][i]]){
				used[v[id][i]] = 1;
				q.push({v[id][i],d + 1});
			}
		}
	}

	return tt;
}

int main(){
	int t = 1;
	int n;

	while(cin >> n && n){
		for(int i = 0;i < 103;++i) v[i].clear();
		mp.clear();
		int cnt = 0;
		for(int i = 0;i < n;++i){
			long long a,b;
			cin >> a >> b;
			if(mp.find(a) == mp.end()){
				mp[a] = cnt++;
			}
			if(mp.find(b) == mp.end()){
				mp[b] = cnt++;
			}
			v[mp[a]].push_back(mp[b]);
			v[mp[b]].push_back(mp[a]);
		}
		int st,m;
		while(cin >> st >> m){
			if(!st && !m) break;
			memset(used,0,sizeof(used));

			cout << "Case " << t++ << ": ";
			if(mp.find(st) == mp.end()){
				cout << mp.size() << " nodes not reachable from node "
				<< st << " with TTL = " << m << ".\n";
			} else {
				cout << mp.size() - bfs(mp[st],m) << " nodes not reachable from node "
				<< st << " with TTL = " << m << ".\n";
			}
		}
	}

	return 0;
}