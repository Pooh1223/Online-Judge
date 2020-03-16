#include <bits/stdc++.h>
using namespace std;

long long dp[55];

int main(){
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2;i < 51;++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int t;
    cin >> t;
    for(int k = 1;k <= t;++k){
        int n;
        cin >> n;
        cout << "Scenario #" << k << ":\n";
        cout << dp[n] << "\n\n";
    }
    return 0;
}
