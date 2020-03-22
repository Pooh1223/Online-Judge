#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> mp;

int main(){
    int t;
    cin >> t;

    while(t--){
        mp.clear();

        int len,st = -1,ed = -1,mn = 300003;
        string s;
        pair<int,int> last = make_pair(0,0);
        mp[last] = -1;

        cin >> len >> s;

        for(int i = 0;i < len;++i){
            if(s[i] == 'R'){
                last.first++;
            } else if(s[i] == 'L'){
                last.first--;
            } else if(s[i] == 'U'){
                last.second++;
            } else {
                last.second--;
            }

            if(i == 0){
                mp[last] = i;
            } else {
                if(mp.find(last) == mp.end()){
                    mp[last] = i;
                    //cout << "Add : " << last.first << " " << last.second << "\n";
                } else {
                    //cout << "Same : " << last.first << " " << last.second << "\n";
                    if(mn > i - mp[last]){
                        mn = i - mp[last];
                        st = mp[last];
                        ed = i;
                    }
                    mp[last] = i;
                }
            }
        }

        if(ed == -1) cout << "-1\n";
        else cout << st + 2<< " " << ed + 1 << "\n";
    }

    return 0;
}
