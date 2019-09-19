#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    while(cin >> s){
        list<char> t;
        list<char>::iterator iter;
        iter = t.begin();
        for(int i = 0;i < s.length();++i){
            if(s[i] == '['){
                iter = t.begin();
            } else if(s[i] == ']'){
                iter = t.end();
            } else {
                t.insert(iter,s[i]);
            }
        }

        for(list<char>::iterator i = t.begin();i != t.end();++i){
            cout << *i;
        }
        cout << "\n";
    }
    return 0;
}
