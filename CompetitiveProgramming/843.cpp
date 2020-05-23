#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<int,int> mp;

    mp[0] = 1 << 30;
    mp[1 << 30] = 0;

    int n,m,q;
    cin >> n >> m >> q;
    
    long long res = (long long)n * m;

    while(q--){
        int x,y;
        cin >> x >> y;

        auto it = mp.lower_bound(x);

        if(it->second >= y){
            cout << "QAQ\n";
            continue;
        }

        long long ans = 0;
        int preh = it->second;
        
        vector<int> del;

        while(1){
            it--;
            ans += (long long)(x - (it->first)) * (min(y,it->second) - preh);
            preh = it->second;

            if(it->second <= y){
                del.push_back(it->first);
            } else break;
        }

        for(int i = 0;i < del.size();++i){
           mp.erase(del[i]);
        }

        mp[x] = y;

        cout << ans << "\n";

        res -= ans;
    }

    cout << res << "\n";

    return 0;
}
