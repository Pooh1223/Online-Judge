#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int m,n;
        char c;
        cin >> c >> n >> m;

        if(c == 'r'){
            cout << min(n,m) << "\n";
        } else if(c == 'k'){
            cout << (n * m % 2 ? n * m / 2 + 1 : n * m / 2) << "\n";
        } else if(c == 'Q'){
            cout << min(n,m) << "\n";
        } else {
            int a = (n % 2 ? n / 2 + 1 : n / 2);
            int b = (m % 2 ? m / 2 + 1 : m / 2);
            cout << a * b << "\n";
        }
    }

    return 0;
}
