#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n,sum = 0;
        cin >> n;

        long long remain = n % 10;

        if(n < 10) cout << n << "\n";
        else {
            while(n >= 10){
                sum += n - remain;
                remain += n / 10;
                n = remain;
                remain = n % 10;
            }
            
            cout << sum + n << "\n";
        }
    }

    return 0;
}
