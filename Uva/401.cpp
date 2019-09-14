#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;

	while(cin >> s){
		bool isPal = 0;
		bool isMir = 1;
		string t = s;
		reverse(s.begin(),s.end());
		if(t == s) isPal = 1;

		for(int i = 0;i < s.length();++i){
			if(s[i] == t[i]){
				if(s[i] == 'A');
				else if(s[i] == 'H');
				else if(s[i] == 'I');
				else if(s[i] == 'M');
				else if(s[i] == 'O');
				else if(s[i] == 'T');
				else if(s[i] == 'U');
				else if(s[i] == 'V');
				else if(s[i] == 'W');
				else if(s[i] == 'X');
				else if(s[i] == 'Y');
				else if(s[i] == '1');
				else if(s[i] == '8');
				else {
					isMir = 0;
					break;
				}
			} else {
				if((s[i] == 'E' && t[i] == '3') || (s[i] == '3' && t[i] == 'E'));
				else if((s[i] == 'J' && t[i] == 'L') || (s[i] == 'L' && t[i] == 'J'));
				else if((s[i] == 'S' && t[i] == '2') || (s[i] == '2' && t[i] == 'S'));
				else if((s[i] == 'Z' && t[i] == '5') || (s[i] == '5' && t[i] == 'Z'));
				else {
					isMir = 0;
					break;
				}
			}
		}
		cout << t;
		if(!isPal && !isMir){
			cout << " -- is not a palindrome.\n\n";
		} else if(!isPal && isMir){
			cout << " -- is a mirrored string.\n\n";
		} else if(isPal && !isMir){
			cout << " -- is a regular palindrome.\n\n";
		} else {
			cout << " -- is a mirrored palindrome.\n\n";
		}
	}

	return 0;
}