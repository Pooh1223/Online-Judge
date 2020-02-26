#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int d,n;
        cin >> d >> n;

        int ans = pow(2,(double)(d - 1));

        bitset<23> bs1(2 * (n - 1));

        string tmp = "";
        for(int i = 0;i < d;++i){
            tmp += char(bs1[i] + '0');
        }

        bitset<23> bs2(tmp);

        ans += bs2.to_ulong();
        cout << ans << "\n";
    }

    return 0;
}
