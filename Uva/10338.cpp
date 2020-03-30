#include <bits/stdc++.h>
using namespace std;

long long nm[23];
int cnt[30];

int main(){
    nm[1] = 1;
    for(int i = 2;i <= 20;++i){
        nm[i] = i * nm[i - 1];
    }

    int n;
    cin >> n;

    for(int tt = 1;tt <= n;++tt){
        memset(cnt,0,sizeof(cnt));

        string s;
        cin >> s;
        //cout << s << "\n"; 
        int len = s.length();

        for(int i = 0;i < len;++i){
            //cout << s[i] - 'A' << "\n";
            cnt[s[i] - 'A']++;
        }

        long long ans = nm[len];

        for(int i = 0;i < 26;++i){
            //cout << nm[cnt[i]] << "\n";
            if(nm[cnt[i]]) ans /= nm[cnt[i]];
        }

        cout << "Data set " << tt << ": " << ans << "\n";
    }

    return 0;
}
