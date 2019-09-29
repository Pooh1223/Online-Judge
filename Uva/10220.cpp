#include <bits/stdc++.h>
using namespace std;

string ans[1003];

string multi(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());

	int na[3003],nb[3003],nm[3003];
	memset(nm,0,sizeof(nm));

	for(int i = 0;i < a.length();++i) na[i] = a[i] - '0';
	for(int i = 0;i < b.length();++i) nb[i] = b[i] - '0';

	for(int i = 0;i < b.length();++i){
		for(int j = 0;j < a.length();++j){
			nm[i + j] += na[j] * nb[i];
		}
	}

	int pos = 0,carry = 0;
	for(;pos < a.length() + b.length();++pos){
		nm[pos] += carry;
		carry = nm[pos] / 10;
		nm[pos] %= 10;
	}

	while(carry){
		nm[pos] = carry % 10;
		carry /= 10;
	}

	string jizz = "";
	
	for(int i = 0;i < pos;++i){
		if(i != pos - 1 || nm[i] != 0) jizz += char(nm[i] + '0');
	}

	reverse(jizz.begin(),jizz.end());

	return jizz;
}

int main(){
	ans[1] = "1";
	
	for(int i = 2;i <= 1000;++i){
		ans[i] = multi(ans[i - 1],to_string(i));
	}

	int n;
	while(cin >> n && n){
        int nm = 0;
        for(int i = 0;i < ans[n].length();++i){
            nm += ans[n][i] - '0';
        }
		cout << nm << "\n";
	}

	return 0;
}

