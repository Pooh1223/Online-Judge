#include <bits/stdc++.h>
using namespace std;

struct edge{
    int a,b,w;
    bool operator<(const edge &a)const{
        return a.w > w;
    }
}v[1003];

int p[103];

int Find(int x){
    if(x == p[x]) return x;
    else return p[x] = Find(p[x]);
}

void Union(int a,int b){
    int pa = Find(a);
    int pb = Find(b);

    p[pa] = pb;
}

int main(){
    int c,s,q,cnt = 1;
    while(cin >> c >> s >> q){
        if(!c && !s && !q) break;
        if(cnt != 1) cout << "\n";

        for(int i = 0;i < s;++i){
            cin >> v[i].a >> v[i].b >> v[i].w;
        }

        sort(v,v + s);
        
        cout << "Case #" << cnt++ << "\n";

        while(q--){
            int st,ed;
            cin >> st >> ed;

            for(int i = 0;i < 103;++i) p[i] = i;
            
            bool ok = 0;

            for(int i = 0;i < s;++i){
                Union(v[i].a,v[i].b);
                if(Find(st) == Find(ed)){
                    cout << v[i].w << "\n";
                    ok = 1;
                    break;
                }
            }

            if(!ok) cout << "no path\n";
        }
    }
    return 0;
}
