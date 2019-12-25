#include <bits/stdc++.h>
using namespace std;

int order[10003];
string p[10003];

int main(){
    int t;
    cin >> t;
    while(getchar() != '\n');

    for(int tt = 0;tt < t;++tt){
        if(tt) cout << "\n";

        string s1 = "",s2 = "";
        while(s1.length() == 0) getline(cin,s1);
        getline(cin,s2);
        
        // make order array
        s1 += " ";
        s2 += " ";

        string tmp = "";
        int pos = 0;
        int n = -1;

        for(int i = 0;i < s1.length();++i){
            if(s1[i] != ' ') tmp += s1[i];
            else {
                order[pos] = stoi(tmp);
                n = max(order[pos],n);
                pos++;
                tmp = "";
            }
        }

        tmp = "";
        pos = 0;
        
        for(int i = 0;i < s2.length();++i){
            if(s2[i] != ' ') tmp += s2[i];
            else {
                p[order[pos] - 1] = tmp;
                pos++;
                tmp = "";
            }
        }

        for(int i = 0;i < n;++i) cout << p[i] << "\n";
    }
    return 0;
}
