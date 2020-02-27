#include <bits/stdc++.h>
using namespace std;

long long c[203][203];

int main(){
    for(int i = 0;i < 203;++i) c[i][0] = 1;
    c[1][1] = 1;
    for(int i = 2;i < 203;++i){
        for(int j = 1;j <= i;++j){
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 1000000;
        }
    }

    int m,n;

    while(cin >> m >> n){
        if(!m && !n) break;

        cout << c[n + m - 1][m] << "\n";
    }

    return 0;
}
