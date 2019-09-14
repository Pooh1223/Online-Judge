#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int len = s.length();
	bool hasVer = 0,hasHor = 0;
	for(int i = 0;i < len;++i){
		if(!hasVer && !hasHor){
			if(s[i] == '0'){
				cout << "1 1\n";
				hasVer = 1;
			} else {
				cout << "4 3\n";
				hasHor = 1;
			}
		} else if(hasVer && !hasHor){
			if(s[i] == '0'){
				cout << "3 1\n";
				hasVer = 0;
			} else {
				cout << "4 3\n";
				hasHor = 1;
			}
		} else if(!hasVer && hasHor){
			if(s[i] == '0'){
				cout << "1 1\n";
				hasVer = 1;
			} else {
				cout << "4 1\n";
				hasHor = 0;
			}
		} else {
			if(s[i] == '0'){
				cout << "3 1\n";
				hasVer = 0;
			} else {
				cout << "4 1\n";
				hasHor = 0;
			}
		}

	}

	return 0;
}