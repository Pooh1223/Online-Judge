#include <bits/stdc++.h>
using namespace std;

bool isWord(char c){
	if(c - 'a' >= 0 && c - 'a' <= 25) return 1;
	else if(c - 'A' >= 0 && c - 'A' <= 25) return 1;
	else return 0;
}

char vowel[] = {'a','e','i','o','u','A','E','I','O','U'};

int main(){
	string s;
	while(getline(cin,s)){
		for(int i = 0;i < s.length();++i){
			if(isWord(s[i])){
				int pos = i;
				while(isWord(s[pos])) pos++;

				bool isVow = 0;
				for(int j = 0;j < 10;++j){
					if(s[i] == vowel[j]){
						isVow = 1;
						break;
					}
				}
					
				if(isVow){
					s.insert(pos,"ay");
				} else {
					string ss = "";
					ss += s[i];
					s.insert(pos,ss + "ay");
					s.erase(i,1);
				}
				i = pos + 2;
			}
		}
		cout << s << "\n";
	}
	return 0;
}