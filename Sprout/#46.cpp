#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int gragh[1005][1005];//,gragh2[1005][1005],gragh3[1005][1005];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int n;
int color[8],ans[8];
int rx[3],ry[3];
int sum = 0;
int cnt = 0;
queue<int> q1,c;
bool boom(int x,int y){
	if(x < 0 || y < 0 || x >= n || y >= n) return 0;
	else return 1;
}
int range(){
	int a = max(max(n - rx[0] - 1,rx[0]),max(n - ry[0] - 1,ry[0]));
	int b = max(max(n - rx[1] - 1,rx[1]),max(n - ry[1] - 1,ry[1]));
	int c = max(max(n - rx[2] - 1,rx[2]),max(n - ry[2] - 1,ry[2]));
	return min(min(a,b),c);
} 
void bfs(int x1,int y1,int sit1,int x2,int y2,int sit2,int x3,int y3,int sit3){
	int nx,ny,nc;
	int time = 0;
	q1.push(x1); q1.push(y1); c.push(sit1);
	q1.push(x2); q1.push(y2); c.push(sit2);
	q1.push(x3); q1.push(y3); c.push(sit3);
	for(int i = 0;!q1.empty();i++){
		int tx = q1.front(); q1.pop();
		int ty = q1.front(); q1.pop();
		int cp = c.front(); c.pop();
		if(i == 0){
			nx = tx;
			ny = ty;
			nc = cp;
		}
		else if(tx == nx && ty == ny){
			q1.push(nx); q1.push(ny); c.push(nc);
			break;
		}
		for(int i = 0;i < 8;i++){
			int xx = tx + dx[i];
			int yy = ty + dy[i];
			if(boom(xx,yy)){
				color[gragh[xx][yy]]--;
				gragh[xx][yy] = (gragh[xx][yy] | cp);
				color[gragh[xx][yy]]++;
				q1.push(xx); q1.push(yy); c.push(cp);
			}
		}
	}
	for(int i = 0;i < 8;i++) ans[i] = max(ans[i],color[i]);
}
int main(){
	//r = 1,y = 2,b = 4;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0;i < 3;i++){
			char color1;
			//scanf("%c %d %d",&color,&rx[i],&ry[i]);
			cin >> color1 >> rx[i] >> ry[i];
			if(color1 == 'R') gragh[rx[i]][ry[i]] = 1;
			else if(color1 == 'Y') gragh[rx[i]][ry[i]] = 2;
			else if(color1 == 'B') gragh[rx[i]][ry[i]] = 4;
			else if(color1 == 'O') gragh[rx[i]][ry[i]] = (1 | 2);
			else if(color1 == 'P') gragh[rx[i]][ry[i]] = (2 | 4);
			else if(color1 == 'G') gragh[rx[i]][ry[i]] = (1 | 4);
			else gragh[rx[i]][ry[i]] = (1 | 2 | 4);
			color[gragh[rx[i]][ry[i]]]++;
			//printf("%c %d %d\n",color,rx[i],ry[i]);
		}
		color[0] = n * n - 3;
		cnt = range();
		printf("%d\n",cnt);
		//bfs(rx[0],ry[0],rx[1],ry[1],rx[2],ry[2]);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				printf("%d ",gragh[i][j]);
			}
			printf("\n");
		}
		char q;
		cin >> q;
		switch(q){
			case 'R':
				printf("%d\n",ans[1]);
				break;
			case 'Y':
				printf("%d\n",ans[2]);
				break;
			case 'O':
				printf("%d\n",ans[3]);
				break;
			case 'B':
				printf("%d\n",ans[4]);
				break;
			case 'P':
				printf("%d\n",ans[5]);
				break;
			case 'G':
				printf("%d\n",ans[6]);
				break;
			case 'D':
				printf("%d\n",ans[7]);
				break;
		}
		memset(ans,0,sizeof(ans));
		memset(color,0,sizeof(color));
		memset(gragh,0,sizeof(gragh));
	}
	return 0;
}