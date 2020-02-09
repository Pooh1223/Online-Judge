#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;

    while(cin >> n >> m){
        long long l = n,r = 44721370;
        
        if(n >= m){
            cout << n << "\n";
            continue;
        }

        while(r - l > 1){
            long long mid = (l + r) / 2;
            long long sum = (n + mid) * (abs(mid - n) + 1) / 2;

            if(sum < m) l = mid;
            else r = mid;
        }
        
        cout << r << "\n";
    }

    return 0;
}
