#include <bits/stdc++.h>
using namespace std;

int main(){
    long long m,n,cnt = 1;

    while(cin >> n >> m){
        if(!n && !m) break;
        bool ok = 0;
        long long ans = 0;
        
        while(ans <= 26){
            if(n <= (m + m * ans)){
                ok = 1;
                break;
            }
            ans++;
        }

        if(ok){
            cout << "Case " << cnt++ << ": " << ans << "\n";
        } else cout << "Case " << cnt++ << ": impossible\n";

    }
    
    return 0;
}
