#include <bits/stdc++.h>
using namespace std;

bool prime[1200];

int main(){
	prime[1] = 1;
	prime[2] = 1;
	for(int i = 3;i < 1200;i += 2){
		bool ck = 0;
		for(int j = 2;j < i;++j){
			if(!(i % j)){
				ck = 1;
				break;
			}
		}
		if(!ck) prime[i] = 1;
	}

	string s;
	string ans = "";
	while(cin >> s){
		int sum = 0;
		for(int i = 0;i < s.length();++i){
			if(s[i] - 'a' >= 0 && s[i] - 'a' <= 25) sum += s[i] - 'a' + 1;
			else sum += s[i] - 'A' + 27;
		}
		if(prime[sum]) ans += "It is a prime word.\n";//cout << "It is a prime word.\n";
		else ans += "It is not a prime word.\n";//cout << "It is not a prime word.\n";
	}
	cout << ans;
	return 0;
}