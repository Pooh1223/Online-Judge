#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int g[103][103];
bool used[103][103];
const int dx[]{0,0,1,-1};
const int dy[]{1,-1,0,0};
int m,n;
int bfs(int x,int y){
	used[x][y] = 1;
	queue<int> q;
	q.push(x); q.push(y);
	int cnt = 0;
	while(!q.empty()){
		int sz = q.size() / 2;
		while(sz--){
			int tx = q.front(); q.pop();
			int ty = q.front(); q.pop();
			if(tx == m && ty == n) return cnt;
			for(int i = 0;i < 4;++i){
				int xx = tx + dx[i];
				int yy = ty + dy[i];
				if(xx < 1 || xx > m || yy < 1 || yy > n) continue;
				if(!used[xx][yy] && abs(g[xx][yy] - g[tx][ty]) <= 5){
					q.push(xx); q.push(yy);
					used[xx][yy] = 1;
				}
			}
		}
		++cnt;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(g,0,sizeof(g));
		memset(used,0,sizeof(used));
		cin >> m >> n;
		for(int i = 1;i <= m;++i){
			for(int j = 1;j <= n;++j){
				cin >> g[i][j];
			}
		}
		cout << bfs(1,1) << "\n";
	}
	return 0;
}