#include <bits/stdc++.h>
using namespace std;

int nm[20003];

int main(){
    
    int t;
    cin >> t;

    for(int tt = 1;tt <= t;++tt){
        int n;
        cin >> n;

        memset(nm,0,sizeof(nm));
        
        int mx_sum = 0,tmp_sum = 0;
        int st= 1,ed = 1,tmp_st = 1;

        for(int i = 1;i <= n - 1;++i) cin >> nm[i];

        for(int i = 1;i <= n - 1;++i){
            tmp_sum += nm[i];

            if(tmp_sum < 0){
                tmp_sum = 0;
                tmp_st = i + 1;
            }

            if(tmp_sum > mx_sum){
                mx_sum = tmp_sum;
                st = tmp_st;
                ed = i + 1;
            } else if(tmp_sum == mx_sum){
                if((ed - st) < (i + 1 - tmp_st)){
                    st = tmp_st;
                    ed = i + 1;
                }
            }
        }

        if(mx_sum <= 0) cout << "Route " << tt << " has no nice parts\n";
        else cout << "The nicest part of route " << tt << " is between stops " << st << " and " << ed << "\n";
    }

    return 0;
}
