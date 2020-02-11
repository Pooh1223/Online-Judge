#include <bits/stdc++.h>
using namespace std;

struct edge{
    int a,b,w;

    bool operator<(const edge &c)const{
        if(c.w != w) return c.w < w;
        else if(c.a != a) return c.a < a;
        return c.b < b;
    }
};

int p[200003];
int sz[200003];

int find(int x){
    if(p[x] == x) return p[x];
    else return p[x] = find(p[x]);
}

int Union(int a,int b){
    int pa = find(a);
    int pb = find(b);

    if(sz[pa] > sz[pb]){
        p[pb] = pa;
        sz[pa] += sz[pb];

        return sz[pa];
    } else {
        p[pa] = pb;
        sz[pb] += sz[pa];

        return sz[pb];
    }
}

int main(){
    int n,m;

    while(cin >> n >> m){
        if(!n && !m) break;
        
        long long sum = 0;
        priority_queue<edge> pq;

        for(int i = 0;i < n;++i){
            p[i] = i;
            sz[i] = 1;
        }

        for(int i = 0;i < m;++i){
            int a,b,w;
            cin >> a >> b >> w;
            sum += w;

            pq.push({a,b,w});
        }
        
        long long ans = 0;

        while(!pq.empty()){
            edge tmp = pq.top();
            pq.pop();
            
            int pa = find(tmp.a),pb = find(tmp.b);

            if(pa != pb){
                if(Union(pa,pb) != n){
                    ans += tmp.w;
                } else {
                    ans += tmp.w;
                    break;
                }
            }
        }

        cout << sum - ans << "\n";
    }

    return 0;
}
