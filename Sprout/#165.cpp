#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int cnt[100005];
bool used[100005];
int ans[100005],jizz;
int main(){
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		for(int i = 0;i < 100005;++i) g[i].clear();
		memset(used,0,sizeof(used));
		memset(cnt,0,sizeof(cnt));
		memset(ans,0,sizeof(ans));
		jizz = 0;
		int n,m;
		cin >> n >> m;
		while(m--){
			int a,b;
			cin >> a >> b;
			g[a].push_back(b);
			cnt[b]++;
		}
		priority_queue< int,vector<int>,greater<int> > pq;
		for(int i = 0;i < n;++i){
			if(cnt[i] == 0){
				pq.push(i);
				used[i] = 1;
			}
		}
		while(!pq.empty()){
			int v = pq.top();
			pq.pop();
			ans[jizz++] = v;
			for(int i = 0;i < g[v].size();++i){
				if(!used[g[v][i]]){
					cnt[g[v][i]]--;
					if(cnt[g[v][i]] == 0){
						pq.push(g[v][i]);
						used[g[v][i]] = 1;
					}
				}
			}
		}
		bool ck = 0;
		for(int i = 0;i < n;++i){
			if(!used[i]){
				 ck = 1;
				 break;
			}
		}
		if(ck) cout << "QAQ\n";
		else{
			cout << ans[0];
			for(int i = 1;i < jizz;++i) cout << " " << ans[i];
			cout <<"\n";
		}
	}
	return 0;
}