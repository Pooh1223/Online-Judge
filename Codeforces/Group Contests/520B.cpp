#include <bits/stdc++.h>
using namespace std;

int ans(int n,int m){
    if(n >= m) return n - m ;
    else if(m % 2 == 1) return 1 + ans(n,m + 1);
    else if(m % 2 == 0) return 1 + ans(n,m / 2);
}

int main(){
    int n,m;
    cin >> n >> m;
    cout << ans(n,m) << "\n";
    return 0;
}
