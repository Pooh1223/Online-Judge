#include <bits/stdc++.h>
#define N 100003
#define M 2000003
using namespace std;
vector<int> v[N];
int sz[N],p[N],gp; // i's boss is p[i]
bool used[N];
void init(){
	for(int i = 0;i < N;++i){
		p[i] = i;
		sz[i] = 1;
	}
}
int find(int x){
	return p[x] == x ? x : p[x] = find(p[x]);
}
void _union(int x,int y){
	int a = find(x);
	int b = find(y);
	gp--;
	if(x == y){
		return;
	}
	if(sz[x] < sz[y]){
		p[x] = y;
		sz[y] += sz[x];
	} else {
		p[y] = x;
		sz[x] += sz[y];
	}
}
int main(){
	init();
	int n,m;
	cin >> n >> m;
	gp = n;
	while(m--){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int cnt = 0;
	for(int i = 1;i <= n;++i){
		memset(used,0,sizeof(used));
		for(int j = 0;j < v[i].size();++j){
			if(!used[v[i][j]]) used[v[i][j]] = 1,cnt++;
		}
		int pos = -1;
		if(cnt >= 2){
			for(int j = 1;j <= n;++j){
				if(j == i) continue;
				if(!used[j] && pos != -1){
					_union(j,pos);
					pos = j;
				} else if(!used[j] && pos == -1){
					pos = j;
				}
			}
		}
	}
	cout << gp << "\n";
	return 0;
}