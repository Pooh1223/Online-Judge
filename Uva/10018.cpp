#include <bits/stdc++.h>
using namespace std;

bool isPal(string s){
	int len = s.length();
	int half = len / 2;
	if(len % 2){
		for(int i = 1;half - i >= 0;++i){
			if(s[half + i] != s[half - i]) return 0;
		}
	} else {
		for(int i = 0;half - i - 1 >= 0;++i){
			if(s[half - i - 1] != s[half + i]) return 0;
		}
	}
	
	return 1;
}

int main(){
	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;
		int cnt = 0;
		
		while(!isPal(s)){
			int len = s.length();
			long long a = 0,b = 0;
			for(int i = 0;i < len;++i){
				a *= 10;
				b *= 10;
				a += s[len - i - 1] - '0';
				b += s[i] - '0';
			}
			s = to_string(a + b);
			cnt++;
		} 
		cout << cnt << " " << s << "\n";
	}

	return 0;
}