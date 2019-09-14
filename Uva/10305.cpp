#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v[103];
bool leaf[103];
bool past[103];

void bfs(){
	queue<int> q;

	for(int i = 1;i <= n;++i){
		if(!leaf[i]){
			q.push(i);
			past[i] = 1;
		} 
	}

	while(!q.empty()){
		int top = q.front();
		cout << top << " ";
		q.pop();

		for(int i = 0;i < v[top].size();++i){
			int u = v[top][i];
			if(!past[u]){
				past[u] = 1;
				q.push(u);
			}
		}
	}
	cout << "\n";
}

int main(){

	while(cin >> n >> m){
		if(!n && !m) break;

		for(int i = 0;i < 103;++i) v[i].clear();
		memset(leaf,0,sizeof(leaf));
		memset(past,0,sizeof(past));
		

		for(int i = 0;i < m;++i){
			int a,b;
			cin >> a >> b;
			v[a].push_back(b);
			leaf[b] = 1;
		}
		bfs();
	}

	return 0;
}