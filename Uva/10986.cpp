#include <bits/stdc++.h>
using namespace std;

struct edge{
	int b;
	long long weight;
};

struct len{
	int id;
	long long ww;
	bool operator<(const len &a)const{
		return a.ww < ww;
	}
};

vector<edge> w[20003];
long long d[20003];
bool used[20003];

int main(){

	int t;
	cin >> t;
	for(int tt = 1;tt <= t;++tt){
		priority_queue<len> pq;
		memset(used,0,sizeof(used));
		fill(d,d + 20003,1e11);
		for(int i = 0;i < 20003;++i) w[i].clear();

		int n,m,st,ed;
		cin >> n >> m >> st >> ed;
		d[st] = 0;

		while(m--){
			int a,b,c;
			cin >> a >> b >> c;
			w[a].push_back({b,c});
			w[b].push_back({a,c});
		}

		pq.push({st,d[st]});

		for(int j = 0;j < n;++j){
            int a = -1;
            while(!pq.empty() && used[a = pq.top().id])
                pq.pop();

            if(a == -1) break;
            used[a] = 1;
            
			for(int i = 0;i < w[a].size();++i){
				int k = w[a][i].b;
				int ww = w[a][i].weight;
				if(!used[k] && d[a] + ww < d[k]){
					d[k] = d[a] + ww;
                    pq.push({k,d[k]});
				}
			}
		}
		cout << "Case #" << tt << ": ";
		if(d[ed] != 1e11) cout << d[ed] << "\n";
		else cout << "unreachable\n";
	}
	return 0;
}
