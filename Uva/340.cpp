#include <bits/stdc++.h>
using namespace std;

int ans[1003];
int nm[1003];
bool used1[1003];
bool used2[1003];

int main(){
    int n,t = 1;
    while(cin >> n && n){
        for(int i = 0;i < n;++i){
            cin >> ans[i];
        }

        cout << "Game " << t++ << ":\n";

        bool ed = 0;

        while(!ed){
            memset(used1,0,sizeof(used1));
            memset(used2,0,sizeof(used2));
            
            int cnt = 0;
            ed = 1;

            for(int i = 0;i < n;++i){
                cin >> nm[i];
                if(nm[i] != 0) ed = 0;
            }

            if(ed) break;

            for(int i = 0;i < n;++i){
                if(ans[i] == nm[i]){
                    cnt++;
                    used1[i] = 1;
                    used2[i] = 1;
                }
            }

            cout << "    (" << cnt << ",";
            cnt = 0;
            
            for(int i = 0;i < n;++i){
                if(used1[i]) continue;
                for(int j = 0;j < n;++j){
                    if(!used2[j] && ans[i] == nm[j]){
                        used1[i] = 1;
                        used2[j] = 1;
                        cnt++;
                        break;
                    }
                }
            }
            cout << cnt << ")\n";
        }
    }

    return 0;
}
