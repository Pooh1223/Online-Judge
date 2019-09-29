#include <bits/stdc++.h>
using namespace std;

int p[10003];

int Find(int u){
	return u == p[u] ? u : p[u] = Find(p[u]);
}

void Union(int x,int y){
	int a = Find(x);
	int b = Find(y);
	p[a] = b;
}

int main(){

	int t;
	cin >> t;
	for(int k = 0;k < t;++k){
		if(k) cout << "\n";

		int n;
		cin >> n;

		for(int i = 0;i < 10003;++i) p[i] = i;

		int yes = 0,no = 0;

		while(getchar() != '\n');

		char c;
		while(c = getchar()){
			
			if(c == '\n' || c == EOF) break;

			int a,b;
			cin >> a >> b;
			getchar();

			if(c == 'c'){
				Union(a,b);
			} else {
				if(Find(a) == Find(b)) yes++;
				else no++;
			}
		}
		cout << yes << "," << no << "\n";
	}
	return 0;
}
