#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int even = 0,odd = 0;

        for(int i = 0;i < n;++i){
            int k;
            cin >> k;

            if(k % 2) odd++;
            else even++;
        }

        if(odd && even) cout << "YES\n";
        else if(odd == 0) cout << "NO\n";
        else if(even == 0 && n % 2 == 0) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
