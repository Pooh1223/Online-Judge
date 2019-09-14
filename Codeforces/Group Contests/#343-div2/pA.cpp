#include <bits/stdc++.h>
using namespace std;
char cake[102][102];
int main(){
	int n;
	cin >> n;
	int column = 0;
	int ans = 0;
	for(int i = 0;i < n;++i){
		for(int j = 0;j < n;++j){
			cin >> cake[i][j];
			if(cake[i][j] == 'C') ++column;
		}
		if(column > 1) ans += (column * (column - 1)) / 2;
		column = 0;
	}
	int row = 0;
	for(int i = 0;i < n;++i){
		for(int j = 0;j < n;++j){
			if(cake[j][i] == 'C') ++row;
		}
		if(row > 1) ans += (row * (row - 1)) / 2;
		row = 0;
	}
	cout << ans << "\n";
	return 0;
}