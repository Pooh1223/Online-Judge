#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		if(a > b) cout << ">\n";
		else if(a < b) cout << "<\n";
		else cout << "=\n";
	}

	return 0;
}