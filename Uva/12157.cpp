#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tt = 1;tt <= t;++tt){

        int n,sum1 = 0,sum2 = 0;
        cin >> n;

        for(int i = 0;i < n;++i){
            int k;
            cin >> k;
            sum1 += (k / 30 + 1) * 10;
            sum2 += (k / 60 + 1) * 15;
        }
        
        cout << "Case " << tt << ": ";
        if(sum1 == sum2){
            cout << "Mile Juice " << sum1 << "\n";
        } else if(sum1 < sum2){
            cout << "Mile " << sum1 << "\n";
        } else {
            cout << "Juice " << sum2 << "\n";
        }
    }
    return 0;
}
