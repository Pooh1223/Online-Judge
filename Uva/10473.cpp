#include <bits/stdc++.h>
using namespace std;

stringstream ss;

void hexToDec(string s){
    ss.str("");
    ss.clear();

    long long nm;
    ss << s;
    ss >> std::hex >> nm;

    cout << nm << "\n";
}

void decToHex(string s){
    ss.str("");
    ss.clear();

    long long nm;
    ss << s;
    ss >> std::dec >> nm;

    ss.str("");
    ss.clear();
    string s1 = "0x";

    ss << std::hex << nm;
    s1 += ss.str();

    for(int i = 2;i <= s1.length();++i){
        if(s1[i] - 'a' >= 0 && s1[i] - 'a' <= 25){
            s1[i] = s1[i] - 'a' + 'A';
        }
    }

    cout << s1 << "\n";
}

int main(){
    string s;
    while(cin >> s){
        if(s[0] == '-') break;
        else if(s[0] == '0') hexToDec(s);
        else decToHex(s);
    }

    return 0;
}
