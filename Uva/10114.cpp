#include <bits/stdc++.h>
using namespace std;

double dep[103];

int main(){
    int m,n;
    double dp,debt;

    while(cin >> m >> dp >> debt >> n){
        if(m <= 0) break;
        memset(dep,0,sizeof(dep));
        
        double pay = debt;
        debt += dp;

        for(int i = 0;i < n;++i){
            int a;
            double b;
            cin >> a >> b;

            for(int j = a;j <= 100;++j){
                dep[j] = 1 - b;
            }
        }
        
        dp = pay / m;

        for(int i = 0;i <= 100;++i){
            if(i) pay -= dp;
            debt *= dep[i];

            if(pay <= debt){
                if(i == 1) cout << "1 month\n";
                else cout << i << " months\n";
                break;
            }
        }
    }

    return 0;
}
