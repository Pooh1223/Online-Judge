#include <bits/stdc++.h>
using namespace std;

int n,m;
int nm[1000003];

bool search(int u){
	int l = 0,r = n - 1;

	while(l <= r){
		int m = (r + l) / 2;

		if(nm[m] < u) l = m + 1;
		else if(nm[m] > u) r = m - 1;
		else return 1; 
	}
	
	return (nm[l] == u);
}

int main(){
	
	while(cin >> n >> m){
		if(!n && !m) break;

		for(int i = 0;i < n;++i) cin >> nm[i];

		int cnt = 0;

		for(int i = 0;i < m;++i){
			int k;
			cin >> k;
			if(search(k)) cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}