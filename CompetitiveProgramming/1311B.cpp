#include <bits/stdc++.h>
using namespace std;

int nm[103];
bool p[103];

int main(){
    int t;
    cin >> t;

    while(t--){
        int n,m;
        bool ok = 1;
        cin >> n >> m;
        
        memset(p,0,sizeof(p));

        for(int i = 0;i < n;++i) cin >> nm[i];
        for(int i = 0;i < m;++i){
            int k;
            cin >> k;
            p[k] = 1;
        }

        for(int i = n - 2;i >= 0 && ok;--i){
            int j = i;
            while(j + 1 < n && nm[j] > nm[j + 1]){
                if(p[j + 1] == 1){
                    swap(nm[j],nm[j + 1]);
                    ++j;
                } else {
                    ok = 0;
                    break;
                }
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
