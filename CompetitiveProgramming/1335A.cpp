#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(n <= 2){
            cout << "0\n";
        } else {
            if(n % 2 == 1) cout << n / 2 << "\n";
            else cout << n / 2 - 1 << "\n";
        }
    }

    return 0;
}
