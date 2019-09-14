#include <bits/stdc++.h>
using namespace std;

long long num[40];

int main(){
	string s;
	num[1] = 1;
	for(int i = 2;i < 33;++i){
		num[i] = (num[i - 1] + 1) * 2 - 1;
	}

	while(cin >> s){
		if(s.length() == 1 && s[0] == '0') break;
		long long n = 0;
		int cnt = s.length();
		for(int i = 0;i < s.length();++i,--cnt){
			n += num[cnt] * (s[i] - '0');
		}
		cout << n << "\n";
	}
	
	return 0;
}