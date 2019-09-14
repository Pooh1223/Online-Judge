#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int cnt = 1;
	
	while(getline(cin,s)){
		
		for(int i = 0;i < s.length();++i){
			if(s[i] == '\"' && cnt){
				cout << "``";
				cnt = 1 - cnt;
			} else if(s[i] == '\"' && !cnt){
				cout << "\'\'";
				cnt = 1 - cnt;
			} else cout << s[i];
		}
		cout << "\n";
	}
	
	return 0;
}