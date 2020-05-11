#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int cnt = 0;
        bool pos = 0;
        ll sum = 0;
        ll mx = -1e9 - 7;

        for(int i = 0;i < n;++i){
            ll k;
            cin >> k;

            if(i == 0){
                if(k > 0) pos = 1;
                mx = max(mx,k);
            } else {
                if(pos == 1 && k > 0){
                    mx = max(mx,k);
                } else if(pos == 0 && k < 0){
                    mx = max(mx,k);
                } else {
                    sum += mx;
                    pos = 1 - pos;
                    mx = -1e9 - 7;
                    mx = max(mx,k);
                }
            }
        }

        cout << sum + mx << "\n";
        
    }

    return 0;
}
