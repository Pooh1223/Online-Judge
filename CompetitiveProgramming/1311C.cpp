#include <bits/stdc++.h>
using namespace std;

struct str{
    int cnt[30];
}record[200005];

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        int m,n;

        cin >> m >> n;
        cin >> s;

        for(int i = 0;i < m;++i){
            for(int j = 0;j < 26;++j) record[i].cnt[j] = 0;

            if(!i){
                record[i].cnt[s[i] - 'a']++;
            } else {
                record[i].cnt[s[i] - 'a']++;
                for(int j = 0;j < 26;++j){
                    record[i].cnt[j] += record[i - 1].cnt[j];
                }
            }
        }

        str ans;

        for(int i = 0;i < 26;++i) ans.cnt[i] = 0;

        for(int i = 0;i < n;++i){
            int k;
            cin >> k;

            for(int j = 0;j < 26;++j) ans.cnt[j] += record[k - 1].cnt[j];
        }

        for(int i = 0;i < 26;++i) cout << ans.cnt[i] + record[m - 1].cnt[i] << " ";
        cout << "\n";
    }

    return 0;
}
