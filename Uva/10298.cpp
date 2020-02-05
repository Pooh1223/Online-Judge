#include <bits/stdc++.h>
using namespace std;

int f[1000003];

void build_f(string s){

    for(int i = 1,j = f[0] = -1;i < s.length();++i){
        while(j >= 0 && s[j + 1] != s[i])
            j = f[j];

        if(s[j + 1] == s[i]) ++j;

        f[i] = j;
    }

    int len = s.length();
    
    if(f[len - 1] + 1 == len - 1) cout << len << "\n";
    else if(f[len - 1] != -1 && !(len % (len - f[len - 1] - 1))) cout << len / (len - f[len - 1] - 1) << "\n";
    else cout << "1\n";
}

int main(){
    string s;
    while(cin >> s){
        if(s == ".") break;

        build_f(s);
    }
    
    return 0;
}
