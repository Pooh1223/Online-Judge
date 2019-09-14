#include <bits/stdc++.h>
using namespace std;

char code[] = {"qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"};

int main(){
	string s;
	while(1){
		char c = getchar();
		if(c == EOF) break;
		else s += c;
	}

	for(int i = 0;i < s.length();++i){
		if(s[i] - 'A' >= 0 && s[i] - 'A' <= 25) s[i] = char(s[i] + 32);
		
		if(s[i] == '\n' || s[i] == ' '){
			cout << s[i];
		} else {
			for(int j = 0;j < strlen(code);++j){
				if(s[i] == code[j]){
					cout << code[j - 2];
				}
			}
		}
	}
	
	return 0;
}