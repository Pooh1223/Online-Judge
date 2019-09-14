#include <bits/stdc++.h>
using namespace std;
unsigned long long c[55][55];
void cal(){
	for(int i = 0;i < 55;++i) c[i][1] = i,c[i][0] = 1;
	for(int i = 1;i < 55;++i){
		for(int j = 1;j < 55;++j){
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cal();
	int n,m;
	while(cin >> n >> m){
		if(n == 0) break;
		cout << c[n + m - 1][m] << "\n";
	}
	return 0;
}