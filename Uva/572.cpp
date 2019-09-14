#include <bits/stdc++.h>
using namespace std;

char mp[103][103];
int dx[] = {1,-1,0,0,1,-1,1,-1};
int dy[] = {0,0,1,-1,1,1,-1,-1};
int n,m;

bool boom(int x,int y){
	return x < 0 || x >= n || y < 0 || y > m;
}


int main(){

	
	while(cin >> n >> m){
		if(!n && !m) break;

		for(int i = 0;i < n;++i)
			for(int j = 0;j < m;++j)
				cin >> mp[i][j];
		
		int cnt = 0;
		for(int i = 0;i < n;++i){
			for(int j = 0;j < m;++j){
				if(mp[i][j] == '@'){
					cnt++;
					queue<int> x;
					queue<int> y;
					x.push(i);
					y.push(j);
					while(!x.empty()){
						int nx = x.front(),ny = y.front();
						x.pop();
						y.pop();
						mp[nx][ny] = '*';

						for(int i = 0;i < 8;++i){
							int tx = nx + dx[i];
							int ty = ny + dy[i];
							if(mp[tx][ty] == '@' && !boom(tx,ty)){
								x.push(tx);
								y.push(ty);
							}
						}

					}
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}