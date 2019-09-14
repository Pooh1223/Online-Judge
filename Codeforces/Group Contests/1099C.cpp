#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int obj;
	cin >> s >> obj;
	int len = 0;
	for(int i = 0;i < s.length();++i) if(s[i] != '?' && s[i] != '*') len++;
	int minus = 0;
	bool chg = 0;
	for(int i = 0;i < s.length();++i){
		if(s[i] == '?'){
			minus++;
			chg = 1;
		} else if(s[i] == '*'){
			chg = 1;
			minus++;
			if(len <= obj){
				bool past = 0;
				for(int j = 0;j < s.length();++j){
					if(s[j] == '?'){
						continue;
					} else if(s[j] == '*' && !past){
						past = 1;
						int circle = obj - len;
						while(circle--) cout << s[j - 1];
					} else if(s[j] == '*'){
						continue;
					} else {
						cout << s[j];
					}
				}
				cout << "\n";
				return 0;
			}
		}
	}

	//cout << "len : " << len << "\nminus : " << minus << "\n";

	if(len - minus > obj){
		cout << "Impossible\n";
	} else if(!chg && len != obj){
		cout << "Impossible\n";
	} else if(len < obj){
		cout << "Impossible\n";
	} else {
		for(int i = 0;i < s.length();++i){
			bool ck;
			if(i + 1 < s.length()) ck = (s[i + 1] == '?' || s[i + 1] == '*');
			else ck = 0;

			if(ck && minus > 0 && len != obj){
				minus--;
				len--;
			} else if(s[i] != '?' && s[i] != '*'){
				cout << s[i];
			}
		}
		cout << "\n";
	}

	return 0;
}