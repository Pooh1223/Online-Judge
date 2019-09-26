#include <bits/stdc++.h>
using namespace std;

map<string,string> m;

int main(){
	string s;
	while(getline(cin,s)){
		if(s.length() == 0) break;
		string ss = "";
		for(int i = 0;i < s.length();++i){
			if(s[i] != ' ') ss += s[i];
			else {
				s.erase(s.begin(),s.begin() + i + 1);
				break;
			}
		}
		m[s] = ss;
	}
	while(cin >> s){
		if(m.find(s) == m.end()) cout << "eh\n";
		else cout << m[s] << "\n";
	}
	return 0;
}