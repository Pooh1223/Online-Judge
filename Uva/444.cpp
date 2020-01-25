#include <bits/stdc++.h>
using namespace std;

stringstream ss;

void encode(string s){
    string tmp = "";
    string ans = "";

    for(int i = 0;i < s.length();++i){
        ss.str("");
        ss.clear();

        ss << int(s[i]);
        tmp = ss.str();

        reverse(tmp.begin(),tmp.end());
        ans += tmp;
    }
    cout << ans << "\n";
}

void decode(string s){
    string tmp = "";

    int cnt = 0;
    int asc = 0;

    for(int i = 0;i < s.length();){

        if(s[i] == '1'){

            for(int j = i;cnt < 3;++j,cnt++){
                tmp += s[j];
            }
            
            ss.str("");
            ss.clear();

            ss << tmp;
            ss >> asc;

            cout << char(asc);

            cnt = 0;
            i += 3;

        } else {

            for(int j = i;cnt < 2;++j,cnt++){
                tmp += s[j];
            }
            
            ss.str("");
            ss.clear();

            ss << tmp;
            ss >> asc;

            cout << char(asc);

            cnt = 0;
            i += 2;
        }

        tmp = "";
    }

    cout << "\n";
}

int main(){
    string s;

    while(getline(cin,s)){
        reverse(s.begin(),s.end());

        if(s[0] - '0' >= 0 && s[0] - '0' <= 9){
            decode(s);
        } else {
            encode(s);
        }
    }

    return 0;
}
