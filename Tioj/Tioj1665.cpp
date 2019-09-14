#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin.tie(0);
	while(cin >> s){
		int len = s.length();
		for(int i = 0;i < s.length();++i){
			if(s[i] == '0') len--;
			else break;
		}
		cout << len << "\n";
	}
	return 0;
}