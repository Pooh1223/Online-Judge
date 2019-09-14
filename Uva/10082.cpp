#include <bits/stdc++.h>
using namespace std;

int main(){
	string s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

	string a;

	while(getline(cin,a)){
		for(int i = 0;i < a.length();++i){
			if(a[i] != ' '){
				for(int j = 0;j < s.length();++j){
					if(s[j] == a[i]){
						cout << s[j - 1];
						break;
					} 
				}
			}
			else cout << a[i];
		}
		cout << "\n";
	}

	return 0;
}