#include <bits/stdc++.h>
using namespace std;

int num[55];

int main(){
	string s;

	while(getline(cin,s,'\n')){
		memset(num,0,sizeof(num));

		for(int i = 0;i < s.length();++i){
			if(s[i] - 'A' >= 0 && s[i] - 'A' <= 25){
				num[s[i]  - 'A']++;
			} else if(s[i] - 'a' >= 0 && s[i] - 'a' <= 25){
				num[s[i] - 'a' + 26]++;
			}
		}	
		int mx = -1;
		for(int i = 0;i < 55;++i) mx = max(mx,num[i]);

		for(int i = 0;i < 52;++i){
			if(num[i] == mx){
				if(i < 26){
					cout << (char)(i + 'A');
				} else {
					cout << (char)(i + 'a' - 26);
				}
			}
		}
		cout << " " << mx << "\n";
	}

	return 0;
}