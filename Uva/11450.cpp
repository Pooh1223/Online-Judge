#include <bits/stdc++.h>
using namespace std;

bool dp[23][203];
vector<int> w[203];

int main(){
    int t;
    cin >> t;

    while(t--){
        
        for(int i = 0;i < 203;++i){
            w[i].clear();
            for(int j = 0;j < 23;++j) dp[j][i] = 0;
        }

        int m,n;
        cin >> m >> n;
        
        for(int i = 0;i < n;++i){
            int q;
            cin >> q;
            
            for(int j = 0;j < q;++j){
                int k;
                cin >> k;
                w[i].push_back(k);
            }
        }

        dp[0][0] = 1;

        for(int i = 0;i < n;++i){
            for(int j = m;j >= 0;--j){
                if(dp[i][j]){
                    for(int k = 0;k < w[i].size();++k){
                        if(j + w[i][k] <= m){
                            dp[i + 1][j + w[i][k]] = 1;
                        }
                    }
                }
            }
        }
        
        bool ok = 0;
        for(int i = m;i >= 0;--i){
            if(dp[n][i]){
                cout << i << "\n";
                ok = 1;
                break;
            }
        }
        if(!ok) cout << "no solution\n";
    }

    return 0;
}
