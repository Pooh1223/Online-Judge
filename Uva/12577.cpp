#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int cnt = 1;
	while(cin >> s){
		if(s.length() == 1) break;
		cout << "Case " << cnt++ << ": ";

		if(s.length() == 4) cout << "Hajj-e-Akbar";
		else cout << "Hajj-e-Asghar";
		cout << "\n";
	}
	return 0;
}