#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        if((n / 2) % 2 == 1){
            cout << "NO\n";
            continue;
        } 
            
        int cnt = 2;
        int odd = 1;

        cout << "YES\n";

        for(int i = 0;i < n;++i){
            if(i < n / 2){
                cout << cnt << " ";
                cnt += 2;
            } else {
                if(i != n - 1) cout << odd << " ";
                else cout << odd + (n / 2) << "\n";
                odd += 2;
            }
        }
    }

    return 0;
}
