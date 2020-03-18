#include <bits/stdc++.h>
using namespace std;

struct matrix{
    int h,w;
};

map<char,matrix> mp;
vector<char> v;

int main(){
    int n;
    cin >> n;

    for(int i = 0;i < n;++i){
        char c;
        int a,b;

        cin >> c >> a >> b;
        mp[c] = matrix({a,b});
    }

    string s;
    while(cin >> s){
        v.clear();
        long long ans = 0;
        bool ed = 0;
        int cnt = 0;

        for(int i = 0;i < s.length() && !ed;++i){
            if(s[i] == ')'){ 
                bool needpush = 0;
                int h1 = -1,h2 = -1,w1 = -1,w2 = -1;

                while(v.size() != 0 && v.back() != '('){
                    char c = v.back();
                    v.pop_back();

                    if((c - 'A' >= 0 && c - 'A' <= 25) || (c - 'a' >= 0)){
                        if(h1 == -1 && w1 == -1){
                            h1 = mp[c].h;
                            w1 = mp[c].w;
                            h2 = h1;
                            w2 = w1;
                        } else {
                            h1 = h2;
                            w1 = w2;
                            h2 = mp[c].h;
                            w2 = mp[c].w;
                            
                            //cout << h1 << " " << w1 << "\n";
                            //cout << c << "\n";
                            //cout << h2 << " " << w2 << "\n";

                            if(w2 == h1){
                                ans += h2 * w1 * w2;
                                
                                mp[char('a' + cnt)] = matrix({h2,w1});

                                //if(mp.find('.') == mp.end()){
                                //    mp['.'] = matrix({h2,w1});
                                //} else {
                                //    mp['.'].h = h2;
                                //    mp['.'].w = w1;
                                //}

                                w2 = w1;
                                needpush = 1;
                            } else {
                                ed = 1;
                                cout << "error\n";
                            }
                        }
                    }
                }
                v.pop_back();
                if(needpush){
                    v.push_back(char('a' + cnt));
                    cnt++;
                }

                //for(int i = 0;i < v.size();++i) cout << v[i];
                //cout << "\n";
            } else {
                v.push_back(s[i]);
            }
        }

        if(!ed) cout << ans << "\n";
    }

    return 0;
}
