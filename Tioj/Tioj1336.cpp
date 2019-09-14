#include <cstdio>
#include <cstring>
#include <queue>
int len,wid;
char map[105][105];
int xx[8] = {0,0,1,-1,1,1,-1,-1};
int yy[8] = {1,-1,0,0,1,-1,1,-1};
char g1 = '-',g2 = 'G';

bool explosion(int x,int y){
	if(x < 0 || y < 0 || x >= wid || y >= len) return 0;
	else return 1;
}

void bfs(int ln,int wd,char qq){
	std :: queue<int> q;
	q.push(ln); q.push(wd);
	map[ln][wd] = 'B';
	while(!q.empty()){
		int tx = q.front(); q.pop();
		int ty = q.front(); q.pop();
		for(int i = 0;i < 8;i++){
			int a = tx + xx[i];
			int b = ty + yy[i];
			if(explosion(a,b) && map[a][b] == qq){
				q.push(a); q.push(b);
				map[a][b] = 'B';
			}
		}
	}
}

int main(){
	scanf("%d %d",&len,&wid);
	for(int i = 0;i < wid;i++){
		for(int j = 0;j < len;j++){
			scanf("%c",&map[i][j]);
			if(map[i][j] == '\n') j--;
		}
	}
	int cnt1 = 0,cnt2 = 0;
	for(int i = 0;i < wid;i++){
		for(int j = 0;j < len;j++){
			if(map[i][j] == '-'){
				cnt1++;
				bfs(i,j,g1);
			}
		}
	}
	for(int i = 0;i < wid;i++){
		for(int j = 0;j < len;j++){
			if(map[i][j] == 'G'){
				cnt2++;
				bfs(i,j,g2);
			}
		}
	}
	printf("%d %d\n",cnt2,cnt1);
	return 0;
}
