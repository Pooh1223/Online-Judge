#include <bits/stdc++.h>
using namespace std;
bool g[103][103];
int n,m;
int dx[] = {1,-1,0,0,1,-1,1,-1};
int dy[] = {0,0,1,-1,1,-1,-1,1};
inline bool boom(int x,int y){
	if(x < 0 || y < 0 || x > n || y > m) return 1;
	return 0;
}
inline int search(int x,int y){
	int ans = 0;
	for(int i = 0;i < 8;++i){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(!boom(tx,ty) && g[tx][ty] == 1) ans++;
	}
	return ans;
}
int main(){
	cin.tie(0);
	while(cin >> n >> m){
		memset(g,0,sizeof(g));
		for(int i = 0;i < n;++i){
			for(int j = 0;j < m;++j){
				cin >> g[i][j];
			}
		}
		for(int i = 0;i < n;++i){
			for(int j = 0;j < m;++j){
				if(!g[i][j]) cout << search(i,j) << " ";
				else cout << "X ";
			}
			cout << "\n";
		}
	}
	return 0;
}