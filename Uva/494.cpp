#include <bits/stdc++.h>
using namespace std;

bool isLetter(char a){
	return (a - 'A' >= 0 && a - 'A' <= 26) 
		|| (a - 'a' >= 0 && a - 'a' <= 26);
}

int main(){
	string s;
	while(getline(cin,s)){
		long long cnt = 0;
		
		for(int i = 0;i < s.length();++i){
			if(isLetter(s[i]));
			else s[i] = ' ';
		}
		bool stu = 1 - isLetter(s[0]);
		long long len = 0;
		while(len < s.length()){
			if(!stu){
				while(len < s.length() && !isLetter(s[len])) len++;
				if(len < s.length()) cnt++;
			} else {
				while(len < s.length() && isLetter(s[len])) len++;
			}
			stu = 1 - stu;
		}
		cout << cnt << "\n";
	}
	return 0;
}