#include <bits/stdc++.h>
using namespace std;

int dx[]{0,1,0,-1,1,1,-1,-1};
int dy[]{1,0,-1,0,1,-1,1,-1};
char mp[103][103];

bool boom(int x,int y,int mxx,int mxy){
	return (x < 0 || x >= mxx || y < 0 || y >= mxy);
}

int main(){

	int m,n;
	int jizz = 1;
	while(cin >> n >> m){
		if(!n && !m) break;
		if(jizz != 1) cout << "\n";
		for(int i = 0;i < n;++i){
			for(int j = 0;j < m;++j){
				cin >> mp[i][j];
			}
		}
		for(int i = 0;i < n;++i){
			for(int j = 0;j < m;++j){
				if(mp[i][j] == '.'){
					int cnt = 0;
					for(int k = 0;k < 8;++k){
						int tx = i + dx[k];
						int ty = j + dy[k];
						if(!boom(tx,ty,n,m) && mp[tx][ty] == '*'){
							cnt++;
						}
					}	
					mp[i][j] = cnt + '0';
				}
			}
		}
		cout << "Field #" << jizz << ":\n";
		for(int i = 0;i < n;++i){
			for(int j = 0;j < m;++j){
				cout << mp[i][j];
			}
			cout << "\n";
		}
		jizz++;
	}

	return 0;
}