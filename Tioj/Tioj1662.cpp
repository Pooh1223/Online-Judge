#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	while(getline(cin,s,'\n')){
		char c = ' ';
		for(int i = 0;i < s.size();++i){
			if(isalpha(s[i])){
				c = s[i];
				if(s[i] <= 'z' && s[i] >= 'a') putchar(toupper(s[i]));
				else putchar(tolower(s[i]));
			} else {
				putchar(' ');
			}
		}
		cout << "\n";
	}
	return 0;
}