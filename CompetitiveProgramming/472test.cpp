#include <bits/stdc++.h>
using namespace std;

map<long long,long long> mp;

int main(){
    int n;
    
    while(cin >> n && n){
        mp.clear();
        long long nm[10];

        for(int i = 0;i < n;++i){
            cin >> nm[i];
        }

        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                long long p = nm[i] * nm[j];

                if(mp.find(p) == mp.end()){
                    mp[p] = 1;
                } else {
                    mp[p]++;
                }
            }
        }

        for(auto kv : mp){
            cout << kv.first << " : " << kv.second << "\n";
        }
    }

    return 0;
}
