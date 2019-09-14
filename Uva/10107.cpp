#include <bits/stdc++.h>
using namespace std;

int v[10005];

int main(){

	int n;
	int cnt = 0;

	while(cin >> n){
		v[cnt++] = n;
		sort(v,v + cnt);
		if(cnt % 2) cout << v[cnt / 2] << "\n";
		else cout << (v[cnt / 2] + v[cnt / 2 - 1]) / 2 << "\n";
	}

	return 0;
}