#include <bits/stdc++.h>
using namespace std;

bool leap(string s){
	int n = (s[0] - '0') * 1 + (s[1] - '0') * 10
		  + (s[2] - '0') * 100 + (s[3] - '0') * 1000;

	if(!(n % 4) && (n % 100 || !(n % 400))) return 1;

	return 0;
}

bool hulu(string s){
	if(s[0] == '0' || s[0] == '5'){
		int sum = 0;
		for(int i = 0;i < s.length();++i) sum += s[i] - '0';

		if(!(sum % 3)) return 1;
	}
	return 0;
}

bool bulu(string s){
	if(s[0] == '0' || s[0] == '5'){
		int even = 0,odd = 0;
		for(int i = 0;i < s.length();++i){
			if(i % 2){
				odd += s[i] - '0';
			} else {
				even += s[i] - '0';
			}
		}

		if(!((abs(odd - even)) % 11)) return true && leap(s);
	}
	return 0;
}

int main(){
	
	int cnt = 0;
	string s;
	while(cin >> s){
		if(cnt) cout << "\n";
		reverse(s.begin(),s.end());
		bool l = leap(s),h = hulu(s),b = bulu(s);

		if(l) cout << "This is leap year.\n";
		if(h) cout << "This is huluculu festival year.\n";
		if(l && b) cout << "This is bulukulu festival year.\n";

		if(!l && !h && !b) cout << "This is an ordinary year.\n";

		cnt++;
	}
	return 0;
}