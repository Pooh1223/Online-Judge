#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(cin >> s){
		if(s == "0") break;
		int odd = 0,even = 0;
		for(int i = 0;i < s.length();++i){
			if(i % 2) odd += s[i] - '0';
			else even += s[i] - '0';
		}
		if(abs(odd - even) % 11) cout << s << " is not a multiple of 11.\n";
		else cout << s << " is a multiple of 11.\n"; 
	}

	return 0;
}