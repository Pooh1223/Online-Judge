#include <bits/stdc++.h>
using namespace std;

struct ins{
    string s;
    int pre;
    int pfrm;
}p[103];

int Find(int x){
    if(x == p[x].pre) return x;
    return p[x].pre = Find(p[x].pre);
}

void Union(int a,int b){
    int aa = Find(a);
    int bb = Find(b);

    p[aa].pre = bb;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        for(int i = 0;i < 103;++i){
            p[i].s = "";
            p[i].pre = i;
        }

        int n,pos = 0;
        cin >> n;

        while(getchar() != '\n');
        
        for(int i = 1;i <= n;++i){
            getline(cin,p[i].s);

            if(p[i].s == "LEFT"){
                pos -= 1;
                p[i].pfrm = -1;
            } else if(p[i].s == "RIGHT"){
                pos += 1;
                p[i].pfrm = 1;
            } else {
                int which;
                string ss = "";
                for(int j = p[i].s.length() - 1;j >= 0;--j){
                    if(p[i].s[j] != ' ') ss += p[i].s[j];
                    else {
                        reverse(ss.begin(),ss.end());
                        break;
                    }
                }
                which = stoi(ss);
                Union(i,which);
                pos += p[Find(i)].pfrm;
            }
        }

        cout << pos << "\n";
    }

    return 0;
}
