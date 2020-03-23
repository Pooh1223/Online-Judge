#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a,b,c,n,lack = 0;
        cin >> a >> b >> c >> n;

        int mx = max(a,max(b,c));

        lack = 3 * mx - a - b - c;

        n -= lack;

        if(n % 3 || n < 0){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}
