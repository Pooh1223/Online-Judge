#include <bits/stdc++.h>
using namespace std;

struct CNT{
    int a,b,c;
}cnt[200003];

bool check(string &s,int len){
    for(int i = 0;i + len - 1 < s.length();++i){
        int pos = i + len - 1;
        if(pos < 0) continue;
        if(i == 0){
            if(cnt[pos].a > 0 && cnt[pos].b > 0 && cnt[pos].c > 0)
                return 1;
            
        } else {
            if(cnt[pos].a > cnt[i - 1].a && cnt[pos].b > cnt[i - 1].b &&
                    cnt[pos].c > cnt[i - 1].c)
                return 1;
        }
    }
    return 0;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        
        for(int i = 0;i < s.length();++i){
            cnt[i].a = 0;
            cnt[i].b = 0;
            cnt[i].c = 0;
        }

        if(s[0] == '1'){
            cnt[0].a = 1;
        } else if(s[0] == '2'){
            cnt[0].b = 1;
        } else if(s[0] == '3'){
            cnt[0].c = 1;
        }

        for(int i = 1;i < s.length();++i){
            if(s[i] == '1'){
                cnt[i].a = cnt[i - 1].a + 1;
                cnt[i].b = cnt[i - 1].b;
                cnt[i].c = cnt[i - 1].c;
            } else if(s[i] == '2'){
                cnt[i].a = cnt[i - 1].a;
                cnt[i].b = cnt[i - 1].b + 1;
                cnt[i].c = cnt[i - 1].c;
            } else if(s[i] == '3'){
                cnt[i].a = cnt[i - 1].a;
                cnt[i].b = cnt[i - 1].b;
                cnt[i].c = cnt[i - 1].c + 1;
            }
            
        }

        int len = s.length() - 1;

        if(cnt[len].a == 0 || cnt[len].b == 0 || cnt[len].c == 0){
            cout << "0\n";
            continue;
        }

        int l = 1,r = s.length();

        while(r - l >= 1){
            int m = (l + r) / 2;
            
            if(check(s,m)) r = m;
            else l = m + 1;
        }

        cout << l << "\n";
        
    }

    return 0;
}
