#include <bits/stdc++.h>
using namespace std;

int main(){
	int h1,m1,h2,m2;

	while(cin >> h1 >> m1 >> h2 >> m2){
		if(!h1 && !m1 && !h2 && !m2) break;

		int t1 = h1 * 60 + m1,t2 = (h2 + 24) * 60 + m2;

		cout << (t2 - t1) % 1440 << "\n";
	}

	return 0;
}