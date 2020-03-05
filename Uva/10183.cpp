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

int isLarger(string a,string b){
    //0 -> b > a ,1 -> a > b ,2 -> a == b

    if(a.length() != b.length()){
        return a.length() > b.length() ? 1 : 0; 
    }

    for(int i = 0;i < a.length();++i){
        if(a[i] - '0' != b[i] - '0'){
            return a[i] - '0' > b[i] - '0' ? 1 : 0;
        }
    }

    return 2;
}

string fib[523];

int main(){
    fib[0] = "0";
    fib[1] = "1";
    fib[2] = "2";

    for(int i = 3;i < 521;++i){
        fib[i] = add(fib[i - 1],fib[i - 2]);
    }
    
    string a,b;
    
    while(cin >> a >> b){
        if(a == "0" && b == "0") break;
        
        int cnt = 0,zero = 0;
        bool st = 0;

        for(int i = 1;i < 520;++i){
            if(isLarger(fib[i],a) != 0 && isLarger(fib[i],b) != 1){
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
