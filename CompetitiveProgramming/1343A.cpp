#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long nm;
        cin >> nm;

        for(long long i = 3;i < 1e9 + 1;i = i * 2 + 1){
            if(nm % i == 0){
                cout << nm / i << "\n";
                break;
            }    
        }
    }

    return 0;
}
