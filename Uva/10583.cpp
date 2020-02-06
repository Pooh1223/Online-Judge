#include <bits/stdc++.h>
using namespace std;

int p[50003]; //parent,size
bool used[50003];

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void Union(int a,int b){
    int pa = find(a);
    int pb = find(b);
    
    p[pa] = pb;
}

int main(){
    int n,m,cnt = 1;

    while(cin >> n >> m){
        if(!n && !m) break;

        for(int i = 1;i <= n;++i) p[i] = i;

        for(int i = 0;i < m;++i){
            int a,b;
            cin >> a >> b;
            Union(a,b);
        }

        int scnt = 0;

        for(int i = 1;i <= n;++i){
            int p = find(i);
            if(!used[p]){
                used[p] = 1;
                scnt++;
            }
        }

        cout << "Case " << cnt++ << ": " << scnt << "\n";

        for(int i = 0;i <= n;++i) used[i] = 0;
    }
    return 0;
}
