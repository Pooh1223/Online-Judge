#include <bits/stdc++.h>
using namespace std;

bool used[10][10];
int cb[10][10];
int ss;
vector<int> v;

bool boom(int x,int y){
	return x < 0 || y < 0 || x >= 8 || y >= 8;
}

bool safe(int x,int y){
	for(int i = 0;i < 8;++i){
		if(used[x][i] || used[i][y]) return 0;
	}

	int dx[] = {1,1,-1,-1};
	int dy[] = {1,-1,1,-1};

	for(int i = 0;i < 4;++i){
		int xx = x + dx[i];
		int yy = y + dy[i];
		while(!boom(xx,yy)){
			if(used[xx][yy]) return 0;
			xx += dx[i];
			yy += dy[i];
		}
	}

	return 1;
}

void dfs(int x,int ans){
	if(x + 1 == 8){
		ss = max(ss,ans);
		return;
	}
	for(int i = 0;i < 8;++i){
		if(!used[x + 1][i] && safe(x + 1,i)){
			used[x + 1][i] = 1;
			ans += cb[x + 1][i];
			dfs(x + 1,ans);
			ans -= cb[x + 1][i];
			used[x + 1][i] = 0;
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(used,0,sizeof(used));
		v.clear();
		for(int i = 0;i < 8;++i)
			for(int j = 0;j < 8;++j)
				scanf("%d",&cb[i][j]);

		ss = -1;

		for(int i = 0;i < 8;++i){
			used[0][i] = 1;
			dfs(0,cb[0][i]);
			used[0][i] = 0;
		}

		printf("%5d\n",ss);
	}

	return 0;
}