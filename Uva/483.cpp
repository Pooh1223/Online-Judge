#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;

	while(getline(cin,s)){
		string rev;
		for(int i = 0;i < s.length();++i){
			if(s[i] == ' ' || i == s.length() - 1){
				if(i == s.length() - 1) rev += s[i];
				reverse(rev.begin(),rev.end());
				cout << rev;
				if(i != s.length() - 1) cout << " ";
				else cout << "\n";
				rev = "";
			} else {
				rev += s[i];
			}
		}
	}

	return 0;
}