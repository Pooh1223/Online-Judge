#include <bits/stdc++.h>
using namespace std;

char mp[503][503];
int dx[]{-1,-1,1,1};
int dy[]{-1,1,-1,1};
int n,cnt = 0;

inline bool boom(int x,int y,int mxn){
	return (x < 0 || y < 0 || x >= mxn || y >= mxn);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 0;i < n;++i){
		for(int j = 0;j < n;++j){
			cin >> mp[i][j];
		}
	}

	if(n >= 3){
		for(int i = 0;i < n;++i){
			for(int j = 0;j < n;++j){
				if(mp[i][j] == 'X'){
					bool x = 1;
					for(int k = 0;k < 4;++k){
						int tx = dx[k] + i;
						int ty = dy[k] + j;
						if(boom(tx,ty,n) || mp[tx][ty] == '.'){
							x = 0;
							break;
						}
					}
					if(x){
						cnt++;
						//cout << i << " " << j << "\n";
					}
				}
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}