#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);

    while(getline(cin,s)){
        if(s[0] != '|') break;
        int sum = 0;
        for(int i = 1;i < s.length();++i){
            if(s[i] == '|') break;
            if(s[i] != '.') sum <<= 1;
            if(s[i] == 'o') sum += 1;
        }
        cout << char(sum);
    }
    return 0;
}
