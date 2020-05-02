#include <bits/stdc++.h>
using namespace std;

long long num[100003];

int parse(string s){
    s += " ";
    string tmp = "";
    int cnt = 0;

    for(int i = 0;i < s.length();++i){
        if(s[i] == ' '){
            num[cnt] = stoll(tmp);
            cnt++;
            tmp = "";
        } else {
            tmp += s[i];
        }
    }

    return cnt;
}

bool check(long long nm,int len){
    for(int i = 0;i < len;++i){
        if(nm < num[i]){
            nm /= 2;
        } else if(nm > num[i]){
            if(num[i] % 2){
                nm += num[i] / 2 + 1;
            } else {
                nm += num[i] / 2;
            }
        }

        if(nm <= 0) return 0;
    }

    return nm > 0;
}

int main(){
    string s;

    while(getline(cin,s)){

        int len = parse(s);

        long long l = 1,r = 1e9 + 6;

        while(r - l >= 1){
            int m = (r + l) / 2;

            if(check(m,len)) r = m;
            else l = m + 1;

        }

        cout << l << "\n";
    }

    return 0;
}
