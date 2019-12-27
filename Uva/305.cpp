#include <bits/stdc++.h>
using namespace std;

int ans[20];

bool check(int k,int count){
    int p = 0;
    for(int i = 0;i < k;++i){
        p = (p + count - 1) % (2 * k - i);
        if(p < k) return 0;
    }
    return 1;
}

int main(){
    int k;
    for(int i = 1;i < 14;++i){
        for(int j = 2;;++j){
            if(check(i,j)){
                ans[i] = j;
                break;
            }
        }
    }

    while(cin >> k && k){
        cout << ans[k] << "\n";
    }
    return 0;
}
