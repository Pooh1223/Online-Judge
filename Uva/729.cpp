#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int tt = 0;tt < t;++tt){
        if(tt) cout << "\n";

        int n,m;
        cin >> n >> m;

        int nm[23];

        for(int i = 0;i < n;++i){
            if(i < n - m) nm[i] = 0;
            else nm[i] = 1;
        }
        
        do{
            for(int i = 0;i < n;++i) cout << nm[i];
            cout << "\n";
        }while(next_permutation(nm,nm + n));

    }

    return 0;
}
