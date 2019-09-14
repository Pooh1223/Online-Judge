#include <cstdio>
#include <queue>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char map[1005][1005];
int n,m;
bool boom(int x,int y){
	if(x < 0 || y < 0 || x >= n || y >= m) return 0;
	else return 1;
}
void bfs(int x,int y){
	queue<int> qq;
	qq.push(x); qq.push(y);
	map[x][y] = '#';
	while(!qq.empty()){
		int tx = qq.front(); qq.pop();
		int ty = qq.front(); qq.pop();
		for(int i = 0;i < 4;i++){
			int xx = tx + dx[i];
			int yy = ty + dy[i];
			if(map[xx][yy] == '.' && boom(xx,yy)){
				map[xx][yy] = '#';
				qq.push(xx); qq.push(yy);
			}
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int cnt = 0;
		scanf("%d %d",&n,&m);
		for(int i = 0;i < n;i++) scanf("%s",map[i]);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '.'){
					bfs(i,j);
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
		cnt = 0;
	}
	return 0;
}