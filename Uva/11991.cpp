#include <bits/stdc++.h>
using namespace std;

map <int,vector<int> > mp;

int main(){
    int m,n;

    while(cin >> m >> n){
        for(int i = 1;i <= m;++i){
            int k;
            cin >> k;

            if(mp.find(k) != mp.end()){
                mp[k].push_back(i);
            } else {
                mp[k] = vector<int>();
                mp[k].push_back(i);
            }
        }

        for(int i = 0;i < n;++i){
            int p,nm;
            cin >> p >> nm;

            if(mp.find(nm) == mp.end()){
                cout << "0\n";
            } else {
                if(mp[nm].size() < p) cout << "0\n";
                else cout << mp[nm][p - 1] << "\n";
            }
        }
    }

    return 0;
}
