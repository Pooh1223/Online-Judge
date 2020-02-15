#include <bits/stdc++.h>
using namespace std;

map<string,long long> mp;

int main(){
    int n,m;
    cin >> n >> m;

    while(n--){
        string s;
        long long val;
        
        cin >> s >> val;
        mp[s] = val;
    }

    while(m--){
        string s;
        long long ans = 0;

        do{
            cin >> s;

            if(mp.find(s) != mp.end()) ans += mp[s];

        }while(s != ".");

        cout << ans << "\n";
    }

    return 0;
}
