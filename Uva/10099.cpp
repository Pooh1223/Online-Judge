#include <bits/stdc++.h>
using namespace std;

struct edge{
    int a,b,w;
    bool operator<(const edge &a)const{
        return a.w < w;
    }
}v[10003];

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
    int c,s,cnt = 1;
    while(cin >> c >> s){
        if(!c && !s) break;

        for(int i = 0;i < s;++i){
            cin >> v[i].a >> v[i].b >> v[i].w;
            v[i].w -= 1;
        }

        sort(v,v + s);
        
        cout << "Scenario #" << cnt++ << "\n";
        cout << "Minimum Number of Trips = ";

        int st,ed,ww;
        cin >> st >> ed >> ww;

        for(int i = 0;i < 103;++i) p[i] = i;
        
        for(int i = 0;i < s;++i){
            Union(v[i].a,v[i].b);
            if(Find(st) == Find(ed)){
                int ans = ww / v[i].w;
                if(ww % v[i].w) ans++;

                cout << ans << "\n\n";
                break;
            }
        }
    }
    return 0;
}

