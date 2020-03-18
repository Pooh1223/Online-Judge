#include <bits/stdc++.h>
using namespace std;

long long c[23];
long long dp[10003];

int main(){
    for(int i = 0;i < 23;++i){
        c[i] = i * i * i;
    }

    dp[0] = 0;
    for(int i = 0;i < 10000;++i) dp[i] = 1;

    for(int i = 2;i <= 21;++i){
        for(int j = c[i];j < 10000;++j){
            dp[j] += dp[j - c[i]];
        }
    }

    int n;
    while(cin >> n){
        cout << dp[n] << "\n";
    }

    return 0;
}
