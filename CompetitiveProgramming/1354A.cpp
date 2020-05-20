#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;

    while(t--){
        long long a,b,c,d;
        cin >> a >> b >> c >> d;

        if(a <= b){
            cout << b << "\n";
        } else if(d >= c){
            cout << "-1\n";
        } else {
            long long l = 0,r = 1e9 + 7;

            while(r - l >= 1){
                long long m = (l + r) / 2;

                if(a <= b + m * (c - d)) r = m;
                else l = m + 1;
            }

            cout << b + l * c << "\n";
        }
    }

    return 0;
}
