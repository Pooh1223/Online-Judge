#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(s.length() == 5) cout << "3\n";
		else {
			string t = "one";
			int dif = 0;
			for(int i = 0;i < 3;++i){
				if(s[i] != t[i]) dif++;
			}
			if(dif <= 1) cout << "1\n";
			else cout << "2\n";
		}
	}

	return 0;
}