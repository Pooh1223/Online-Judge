#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int building,m;
	cin >> building >> m;
	long long mx[(int)log2(building) + 5][building + 5],mn[(int)log2(building) + 5][building + 5];
	for(int i = 0;i < building;i++){
		cin >> mx[0][i];
		mn[0][i] = mx[0][i];
	} 
	for(int y = 1;(1 << y) <= building;y++){
		for(int x = 0;x + (1 << y) <= building;x++){
			mx[y][x] = max(mx[y - 1][x],mx[y - 1][x + (1 << (y - 1))]);
			mn[y][x] = min(mn[y - 1][x],mn[y - 1][x + (1 << (y - 1))]);
		}
	}
	while(m--){
		int l,r;
		cin >> l >> r;
		int p = 31 - __builtin_clz(abs(r - l) + 1);
		cout << max(mx[p][l - 1],mx[p][r - (1 << p)])
				- min(mn[p][l - 1],mn[p][r - (1 << p)])
				 << endl;
	}
	return 0;
} 
