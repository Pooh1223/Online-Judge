#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int a,b;
        bool ok = 1;

        for(int i = 0;i < n;++i){
            if(!i) cin >> a;
            else {
                cin >> b;
                if((a % 2) != (b % 2)){
                    ok = 0;
                }
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
