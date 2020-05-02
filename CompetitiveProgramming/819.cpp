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
	if(carry) ans += "1";
	reverse(ans.begin(),ans.end());
	return ans;
}

string striplz(string s){
    for(int i = 0;i < s.length();++i){
        if(s[i] == '0'){
            s.erase(i,1);
            --i;
        } else {
            break;
        }
    }

    return s;
}

string separate(string s){
    string ans = "";
    string tmp = "";

    for(int i = 0;i < s.length();++i){
        if(s[i] == ' '){
            tmp = striplz(tmp);
            if(ans.length() == 0){
                ans = tmp;
            } else {
                ans = add(ans,tmp);
            }
            tmp = "";
            while(s[i] == ' ') ++i;
            --i;
        } else {
            tmp += s[i];
        }
    }
    return ans;
}

int main(){
    string s;

    while(getline(cin,s)){
        s += " ";
        cout << separate(s) << "\n";
    }

    return 0;
}
