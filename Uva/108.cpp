#include <bits/stdc++.h>
using namespace std;

int num[103][103];

int main(){

	int n;
	cin >> n;

	int mx = -9999999;

	for(int i = 0;i < n;++i){
		for(int j = 0;j < n;++j){
			cin >> num[i][j];
			if(i) num[i][j] += num[i - 1][j];
			if(j) num[i][j] += num[i][j - 1];
			if(i && j) num[i][j] -= num[i - 1][j - 1];
			mx = max(mx,num[i][j]);
		}
	}

	for(int x = 0;x < n;++x){
		for(int y = 0;y < n;++y){
			int now = num[x][y];
			for(int i = 0;i <= x;++i){
				for(int j = 0;j <= y;++j){
					int sum = now;
					if(i) sum -= num[i - 1][y];
					if(j) sum -= num[x][j - 1];
					if(i && j) sum += num[i - 1][j - 1];
					mx = max(mx,sum);
				}
			}
		}
	}
	
	cout << mx << "\n";

	return 0;
}