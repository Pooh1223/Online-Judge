#include <bits/stdc++.h>
using namespace std;

string add(string a,string b){
	string ans = "";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());

	if(a.length() < b.length()) swap(a,b);
	int carry = 0;

	for(int i = 0;i < a.length();++i){
		int q = a[i] - '0',p = 0;
		if(i < b.length()) p = b[i] - '0';

		ans += to_string((q + p + carry) % 10);

		if(q + p + carry >= 10){
			carry = 1;
		} else {
			carry = 0;
		}
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	int t;
	cin >> t;
	for(int k = 0;k < t;++k){
		if(k) cout << "\n";
		int n;
		cin >> n;
		string a = "",b = "";
		char c;
		for(int i = 0;i < n * 2;++i){
			cin >> c;
			if(i % 2) a += c;
			else b += c;
		}
		cout << add(a,b) << "\n";
	}
	return 0;
}