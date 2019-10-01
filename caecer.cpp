#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	for(int j = 0;j < 128;++j){
		for(int i = 0;i < s.length();++i){
			/*if(s[i] - 'A' >= 0 && s[i] - 'A' <= 25){
				cout << char((s[i] - 'A' + (j + 26)) % 26 + 'A');
			} else if(s[i] - 'a' >= 0 && s[i] - 'a' <= 25){
				cout << char((s[i] - 'a' + (j + 26)) % 26 + 'a');
			} else {
				cout << s[i];
			}*/
			cout << char((s[i] + (j + 128)) % 128);
		}
		cout << "\n";
	}
	
	return 0;
}