#include <bits/stdc++.h>
using namespace std;

bool live[153];
int ans[153];

int main(){
    for(int i = 0;i < 153;++i) ans[i] = -1;
    int n;

    while(cin >> n && n){
        if(ans[n] != -1){
            cout << ans[n] << "\n";
            continue;
        }

        int pos = 1;
        
        for(int i = 2;;++i){
            memset(live,0,sizeof(live));
            pos = 1;
            bool ok = 1;

            for(int j = 0;j < n - 1;++j){
                if(pos == 2){
                    ok = 0;
                    break;
                }
                live[pos] = 1;
                
                int cnt = 0;
                while(cnt < i){
                    if(pos < n) pos += 1;
                    else pos = 2;

                    if(!live[pos]){
                        cnt++;
                    }
                }
            }
            
            if(ok){
                cout << i << "\n";
                ans[n] = i;
                break;
            }
        }
        
    }

    return 0;
}
