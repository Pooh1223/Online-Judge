#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,ans = "";
	while(cin >> s){
		if(s == "0") break;
		if(ans == ""){
			ans = s;
			reverse(ans.begin(),ans.end());
			continue;
		}

		reverse(s.begin(),s.end());
		if(ans.length() < s.length()) swap(ans,s);

		bool carry = 0;
		for(int i = 0;i < s.length();++i){
			int a = s[i] - '0',b = ans[i] - '0';
			string tmp = to_string(a + b + carry);
			if(a + b + carry >= 10){
				ans[i] = tmp[1];
				carry = 1;
			} else {
				ans[i] = tmp[0];
				carry = 0;
			}
		}
		for(int i = s.length();i < ans.length();++i){
			int a = ans[i] - '0';
			string tmp = to_string(a + carry);
			if(a + carry >= 10){
				ans[i] = tmp[1];
				carry = 1;
			} else {
				ans[i] = tmp[0];
				carry = 0;
				break;
			}
		}
		if(carry) ans += '1';
	}
	reverse(ans.begin(),ans.end());
	cout << ans << "\n";
	return 0;
}