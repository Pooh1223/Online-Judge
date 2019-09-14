#include <bits/stdc++.h>
using namespace std;
int g[3003][3003];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int m,n;
bool boom(int x,int y,int xx,int yy){
	if(x >= xx || x < 0 || y >= yy || y < 0) return 1;
	else return 0;
}
int bfs(int x,int y){
	int sz = 1;
	queue<int> q;
	int race = g[x][y];
	g[x][y] = -1;
	q.push(x); q.push(y);
	while(!q.empty()){
		int xx = q.front(); q.pop();
		int yy = q.front(); q.pop();
		for(int i = 0;i < 4;++i){
			int tx = xx + dx[i];
			int ty = yy + dy[i];
			if(!boom(tx,ty,m,n) && g[tx][ty] == race){
				g[tx][ty] = -1;
				q.push(tx); q.push(ty);
				sz++;
			}
		}
	}
	return sz;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for(int i = 0;i < m;++i){
		for(int j = 0;j < n;++j){
			cin >> g[i][j];
		}
	}
	int ans = 0;
	for(int i = 0;i < m;++i){
		for(int j = 0;j < n;++j){
			if(g[i][j] >= 0) ans = max(ans,bfs(i,j));
		}
	}
	cout << ans << "\n";
	return 0;
}