#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(getchar() != '\n');

	while(t--){
		string s;
		getline(cin,s,'\n');

		if(!s.length()){
			cout << "Yes\n";
			continue;
		}
		
		string tmp = "";
		for(int i = 0;i < s.length();++i){
			if(s[i] != ' ') tmp += s[i];
		}
		s = tmp;

		if(s.length() % 2){
			cout << "No\n";
			continue;
		}

		bool next = 1;
		
		while(next){
			next = 0;
			for(int i = 0;i < s.length();++i){
				if(i + 1 < s.length()){
					if(s[i] == '(' && s[i + 1] == ')'){
						next = 1;
						s[i] = ' ';
						s[i + 1] = ' ';
					} else if(s[i] == '[' && s[i + 1] == ']'){
						next = 1;
						s[i] = ' ';
						s[i + 1] = ' ';
					}
				}
			}
			if(next){
				tmp = "";
				for(int i = 0;i < s.length();++i){
					if(s[i] != ' ') tmp += s[i];
				}
				s = tmp;
			}
		}

		if(s.length()) cout << "No\n";
		else cout << "Yes\n";
	}

	return 0;
}