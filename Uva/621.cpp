#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(s == "1" || s == "4" || s == "78"){
			cout << "+\n";
		} else if(s[s.length() - 2] == '3' && s[s.length() - 1] == '5'){
			cout << "-\n";
		} else if(s[0] == '1' && s[1] == '9' && s[2] == '0'){
			cout << "?\n";
		} else {
			cout << "*\n";
		}
	}
	return 0;
}