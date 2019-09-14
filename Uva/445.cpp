#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int cnt = 0;

	while(getline(cin,s,'\n')){
		if(s == "\n"){
			cnt++;
			continue;
		}
		if(cnt) cout << "\n";
		int pos = 0;

		while(pos < s.length()){
			int sum = 0;
			for(;pos < s.length();++pos){
				int n = s[pos] - '0';
				if(n >= 0 && n < 10) sum += n;
				else break;
			}
			if(s[pos] == 'b'){
				while(sum--) cout << ' ';
			} else if(s[pos] == '!'){
				cout << "\n";
			} else {
				while(sum--) cout << s[pos];
			}
			pos++;
		}
		cout << "\n";
	}

	return 0;
}