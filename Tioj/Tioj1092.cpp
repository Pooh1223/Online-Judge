#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ans,g[10003];
bitset<10003> win;
int out[10003];
void bfs(){
	queue<int> q;
	win[n] = 1;
	q.push(n);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = 0;i < g[u].size();++i){
			int v = g[u][i];
			if(win[u] == 1){
				win[v] = 0;
				out[v]--;
				if(!out[v]) q.push(v);
			} else {
				out[v]--;
				if(!out[v]) q.push(v);	
			}
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	while(cin >> n >> m){
		if(!n && !m) break;
		memset(out,0,sizeof(out));
		for(int i = 0;i < 10003;++i){
			g[i].clear();
		}
		win.set();
		while(m--){
			int a,b;
			cin >> a >> b;
			out[a]++;
			g[b].push_back(a);
		}
		bfs();
		string s;
		cin >> s;
		if(win[1] == 1) cout << s << "\n";
		else if(s == "Mimi") cout << "Moumou\n";
		else cout << "Mimi\n"; 
	}
	return 0;
}