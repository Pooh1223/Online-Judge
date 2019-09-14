#include <bits/stdc++.h>
#define N 103
#define M 503
using namespace std;
bool g[N][N];
vector<int> v[N];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	while(m--){
		string s;
		int a,b;
		cin >> a >> s >> b;
		if(s == "->"){
			v[a].push_back(b);
			g[a][b] = 1;
		} else {
			v[b].push_back(a);
			g[b][a] = 1;
		}
	}
	if(!k){
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= n;++j){
				cout << g[i][j] << " ";
			}
			cout << "\n";
		}
	} else {
		for(int i = 1;i <= n;++i){
			cout << i << " -> ";
			if(v[i].empty()){
				cout << 0 << "\n";
				continue;
			} 
			sort(v[i].begin(),v[i].end());
			vector<int>::iterator iter = unique(v[i].begin(),v[i].end());
			v[i].erase(iter,v[i].end());
			for(int j = 0;j < v[i].size();++j){
				cout << v[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}