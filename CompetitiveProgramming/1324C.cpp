#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        string s;
        cin >> s;
        int mx = 0;

        for(int i = 0;i < s.length();){
            int tmp = 0;
            while(s[i] == 'L'){
                tmp++;
                i++;
            }
            mx = max(tmp,mx);
            if(!tmp) i++;
        }

        cout << mx + 1 << "\n";
    }

    return 0;
}
