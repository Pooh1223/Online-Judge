#include <bits/stdc++.h>
using namespace std;

string able[100];
bool used[10];

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

bool legal(string s,bool type){
	if(s.length() > 5) return 0;

	if(!type) memset(used,0,sizeof(used));

	if(s.length() == 4){
		if(used[0]) return 0;
		else used[0] = 1;

		for(int i = 0;i < s.length();++i){
			if(used[s[i] - '0']) return 0;
			else used[s[i] - '0'] = 1;
		}
	} else {
		for(int i = 0;i < s.length();++i){
			if(used[s[i] - '0']) return 0;
			else used[s[i] - '0'] = 1;
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for(int i = 2;i <= 79;++i){
		string s = "1234";
		legal(s,0);
		string ss = "";

		bool ok = 0;

		while(ss.length() <= 5){
			ss = multi(s,to_string(i));
			if(!legal(ss,1)){
				while(!legal(s = add(s,"1"),0));
				continue;
			}
			else {
				if(s.length() != 4) able[i] += ss + " / " + s + " = " + to_string(i) + "\n";
				else able[i] += ss + " / 0" + s + " = " + to_string(i) + "\n";
				ok = 1;
			} 
			while(!legal(s = add(s,"1"),0));
			
		}
		if(!ok) able[i] += "There are no solutions for " + to_string(i) + ".\n";
	}

	int n;
	int cnt = 0;
	while(cin >> n && n){
		if(cnt) cout << "\n";
		cout << able[n];
		cnt++;
	}
	return 0;
}