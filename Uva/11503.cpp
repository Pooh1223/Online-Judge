#include <bits/stdc++.h>
using namespace std;

map<string,int> mp;

int p[100003];
int sz[100003];

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

int Union(int a,int b){
    int pa = find(a);
    int pb = find(b);
    
    if(pa == pb) return sz[pa];

    int sza = sz[pa];
    int szb = sz[pb];

    if(sza < szb){
        p[pa] = pb;
        sz[pb] += sz[pa];
        return sz[pb];
    } else {
        p[pb] = pa;
        sz[pa] += sz[pb];
        return sz[pa];
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n,cnt = 0;
        cin >> n;
        
        for(int i = 0;i < 100003;++i){
            p[i] = i;
            sz[i] = 1;
        }

        mp.clear();

        for(int i = 0;i < n;++i){
            string a,b;
            cin >> a >> b;

            int na,nb;

            if(mp.find(a) == mp.end()){
                mp[a] = cnt;
                na = cnt++;
            } else {
                na = mp[a];
            }

            if(mp.find(b) == mp.end()){
                mp[b] = cnt;
                nb = cnt++;
            } else {
                nb = mp[b];
            }
             
            cout << Union(na,nb) << "\n";
        }
    }

    return 0;
}
