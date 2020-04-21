#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        if(s == "0") break;
        
        int nm = 0;

        for(int i = 0;i < s.length();++i){
            nm = nm * 10 + (s[i] - '0');
            nm %= 17;
        }

        if(nm != 0){
            cout << "0\n";
        } else {
            cout << "1\n";
        }
    }
    return 0;
}
