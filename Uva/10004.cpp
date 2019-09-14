#include <bits/stdc++.h>
using namespace std;

vector<int> v[203];
int color[203];

bool dfs(int u){

	for(int i = 0;i < v[u].size();++i){
		if(color[v[u][i]] == color[u]){
			return 0;
		}
		if(!color[v[u][i]]){
			color[v[u][i]] = -color[u];
			if(!dfs(v[u][i])) return 0; 
		}
	}

	return 1;
}

int main(){

	int n;
	
	while(cin >> n){
		if(!n) break;

		int m;
		cin >> m;

		for(int i = 0;i < 203;++i) v[i].clear();
		memset(color,0,sizeof(color));

		for(int i = 0;i < m;++i){
			int a,b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		bool jizz = 1;

		color[0] = 1;

		for(int i = 0;i < n;++i){
			if(!dfs(0)){
				cout << "NOT BICOLORABLE.\n";
				jizz = 0;
				break;
			}
		}
		if(jizz) cout << "BICOLORABLE.\n";
	}

	return 0;
}