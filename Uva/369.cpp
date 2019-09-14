#include <bits/stdc++.h>
using namespace std;

long long c[103][103];

int main(){
	c[0][0] = 1;
	for(int i = 0;i < 103;++i){
		for(int j = 1;j < 103;++j){
			if(!i) c[j][i] = 1;
			else c[j][i] = c[j - 1][i] + c[j - 1][i - 1];
		}
	}

	int n,m;
	while(cin >> n >> m){
		if(!n && !m) break;
		cout << n << " things taken " << m << " at a time is " << 
		c[n][m] << " exactly.\n";
	}
	
	return 0;
}