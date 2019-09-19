#include <bits/stdc++.h>
using namespace std;

int v[50003];

void ans(int u,int n){
    int l = 0,r = n - 1;

    while(l <= r){
        int m = (l + r) / 2;
        if(v[m] > u) r = m - 1;
        else if(v[m] < u) l = m + 1;
        else{
            if(m - 1 < 0) cout << "X ";
            else cout << v[m - 1] << " ";
            if(m + 1 >= n) cout << "X\n";
            else cout << v[m + 1] << "\n";

            return;
        }
    }

    if(l == n){
        cout << v[l - 1] << " X\n";
    } else if(l == 0){
        cout << "X " << v[l] << "\n";
    } else {
        cout << v[l - 1] << " " << v[l] << "\n";
    }
    
}

int main(){

    int n,cnt = 0;
    cin >> n;
    for(int i = 0;i < n;++i){
        int k;
        cin >> k;
        if(i){
            if(v[cnt - 1] != k){
                v[cnt++] = k;
            }
        } else {
            v[cnt++] = k;
        }
    }

    int q;
    cin >> q;
    while(q--){
        int h;
        cin >> h;

        ans(h,cnt);
    }
    return 0;
}
