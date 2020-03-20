#include <bits/stdc++.h>
using namespace std;

int nm[5003];

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        bool ok = 0;
        
        for(int i = 0;i < n;++i){
            cin >> nm[i];
        }

        for(int i = 0;i < n;++i){
            for(int j = i + 2;j < n;++j){
                if(nm[i] == nm[j]){
                    ok = 1;
                    break;
                }
            }
        }
        
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
