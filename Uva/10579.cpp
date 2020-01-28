#include <bits/stdc++.h>
using namespace std;

string fib[10003];

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
	if(carry) ans += "1";
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
    fib[1] = "1";
    fib[2] = "1";

    for(int i = 3;i < 10003 && fib[i - 1].length() < 1000;++i){
        fib[i] = add(fib[i - 1],fib[i - 2]);
    }

    int n;

    while(cin >> n){
        cout << fib[n] << "\n";
    }

    return 0;
}
