#include <bits/stdc++.h>
using namespace std;

long long nm[21];

int main(){
    int cnt = 1;
    
    int t;
    
    while(cin >> t){
        long long ans = 0;

        for(int i = 0;i < t;++i) cin >> nm[i];

        for(int l = 1;l <= t;++l){

            for(int i = 0;i <= t - l;++i){

                long long tmp = 1;

                for(int j = 0;j < l;++j){
                    tmp *= nm[i + j];
                }
                ans = max(ans,tmp);

            }
            
        }

        cout << "Case #" << cnt++ << ": The maximum product is " << ans << ".\n\n";
    }

    return 0;
}
