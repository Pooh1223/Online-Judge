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

string subtract(string a,string b){
	string ans = "";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());

	if(a.length() < b.length()) swap(a,b);

	for(int i = 0;i < a.length();++i){
		int q = a[i] - '0',p = 0;
		if(i < b.length()) p = b[i] - '0';

		if(!q && !p) continue;
		if(q < p){
			int pos = i + 1;
			while(pos < a.length()){
				if(a[pos] - '0' > 0){
					a[pos] = char(a[pos] - 1);
					break;
				} else {
					a[pos++] = '9';
				}
			}
			ans += to_string(q - p + 10);
		} else {
			ans += to_string(q - p);
		}
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

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


string divise(string a,string b){
	string ans = "";
	
	return ans;
}

int main(){
	string a,b;
	cin >> a >> b;

	cout << add(a,b) << "\n";
	cout << subtract(a,b) << "\n";
	cout << multiple(a,b) << "\n";
	cout << divise(a,b) << "\n";
	
	return 0;
}