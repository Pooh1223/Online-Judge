#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;

	while(cin >> s){
		for(int i = 0;i < s.length();++i){
			int num = s[i] - 'A';
			if(num >= 0 && num <= 2) cout << "2";
			else if(num >= 3 && num <= 5) cout << "3";
			else if(num >= 6 && num <= 8) cout << "4";
			else if(num >= 9 && num <= 11) cout << "5";
			else if(num >= 12 && num <= 14) cout << "6";
			else if(num >= 15 && num <= 18) cout << "7";
			else if(num >= 19 && num <= 21) cout << "8";
			else if(num >= 22 && num <= 25) cout << "9";
			else cout << s[i];
		}
		cout << "\n";
	}

	return 0;
}