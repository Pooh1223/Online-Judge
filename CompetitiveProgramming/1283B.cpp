#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a,b;
        cin >> a >> b;

        if(!(a % b)){
            cout << a << "\n";
        } else {
            int m = a % b;

            if(m > b / 2){
                cout << a - (m - b / 2) << "\n";
            } else {
                cout << a << "\n";
            }
        }
    }

    return 0;
}
