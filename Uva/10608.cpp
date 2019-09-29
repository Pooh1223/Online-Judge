#include <bits/stdc++.h>
using namespace std;

int p[30003],sz[30003];

int Find(int u){
	return u == p[u] ? u : p[u] = Find(p[u]);
}

void Union(int x,int y){
	int a = Find(x);
	int b = Find(y);

	if(a == b) return;
	else if(sz[a] > sz[b]){
		p[b] = a;
		sz[a] += sz[b];
	} else {
		p[a] = b;
		sz[b] += sz[a];
	}
	
}

int Size(int u){
	return sz[Find(u)];
}

int main(){

	int t;
	cin >> t;
	while(t--){

		for(int i = 0;i < 10003;++i){
			p[i] = i;
			sz[i] = 1;
		} 

		int n,m;
		cin >> n >> m;

		while(m--){
			int a,b;
			cin >> a >> b;
			Union(a,b);
		}

		int mx = -1;
		for(int i = 1;i <= n;++i){
			//cout << i << " : " << sz[i] << "\n";
			mx = max(sz[i],mx);
		}
		cout << mx << "\n";
	}
	return 0;
}