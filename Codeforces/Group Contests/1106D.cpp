#include <bits/stdc++.h>
using namespace std;

vector<int> v[100005];
priority_queue<int ,vector<int> ,greater<int> > pq;
bool used[100005];

void bfs(int u){
	used[u] = 1;
	pq.push(u);
	while(!pq.empty()){
		int top = pq.top();
		pq.pop();
		cout << top << " ";
		for(int i = 0;i < v[top].size();++i){
			if(!used[v[top][i]]){
				pq.push(v[top][i]);
				used[v[top][i]] = 1;
			}
		}
	}
}

int main(){

	int n,m;
	cin >> n >> m;

	for(int i = 0;i < m;++i){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs(1);

	return 0;
}