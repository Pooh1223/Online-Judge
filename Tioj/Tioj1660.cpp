#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin.tie(0);
	while(cin >> s){
		int n = s.size();
		bool ck = 0;
		for(int i = 0,j = n - 1;i < n && j >= 0;++i,--j){
			if(s[i] != s[j]){
				ck = 1;
				break;
			}
		}
		if(ck) cout << "not palindrome\n";
		else cout << "palindrome\n";
	}
	return 0;
}