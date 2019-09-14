#include <cstdio>
#include <string>
#include <queue>
using namespace std;

char board[1005][1005];
int xx[] = {0,0,-1,1,-1,1,-1,1};
int yy[] = {-1,1,0,0,-1,-1,1,1};
int cnt = 0;
int len,wid;

int boom(int x,int y){
	if(x < 0 || y < 0 || x >= len || y >= wid) return 0;
	else return 1;
}

void bfs(int ln,int wd){
	queue<int> q;
	board[ln][wd] = '0';
	q.push(ln); q.push(wd);
	while(!q.empty()){
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		for(int i = 0;i < 8;i++){
			int a = x + xx[i];
			int b = y + yy[i];
			if(boom(a,b) && board[a][b] == '1'){
				board[a][b] = '0';
				q.push(a);
				q.push(b);
			}
		}
	}
}

int main(){
	while(~scanf("%d %d",&len,&wid)){
		if(!len && !wid) break;
		for(int i = 0;i < len;i++) scanf("%s",board[i]);	
		for(int i = 0;i < len;i++){
			for(int j = 0;j < wid;j++){
				if(board[i][j] == '1'){
					//printf("%d %d\n",i,j);
					cnt++;
					bfs(i,j);
				} 
			}
		}
		printf("%d\n",cnt);
		cnt = 0;
	}
	return 0;
}
