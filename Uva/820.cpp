#include <bits/stdc++.h>
#define N 103
using namespace std;

int r[N][N];
int path[N];

int main(){
    int n,cnt = 1;
    while(cin >> n && n){
        int s,t,m;
        cin >> s >> t >> m;

        memset(r,0,sizeof(r));

        for(int i = 0;i < m;++i){
            int a,b,w;
            cin >> a >> b >> w;
            r[a][b] += w;
            r[b][a] += w;
        }

        int flow = 0;

        while(1){
            memset(path,0,sizeof(path));

            queue<int> q;
            q.push(s);
            path[s] = s;

            while(!q.empty() && !path[t]){
                int u = q.front();
                q.pop();

                for(int i = 1;i <= n;++i){
                    if(!path[i] && r[u][i] > 0){
                        path[i] = u;
                        q.push(i);
                    }
                }
            }
                //no more argumenting path
            if(!path[t]) break;

            int nflow = 1e9;

            for(int i = path[t],j = t;i != j;i = path[j = i]){
                nflow = min(nflow,r[i][j]);
            }

            for(int i = path[t],j = t;i != j;i = path[j = i]){
                r[i][j] -= nflow;
                r[j][i] += nflow;
            }

            flow += nflow;
        }

        cout << "Network " << cnt++ << "\n";
        cout << "The bandwidth is " << flow << ".\n\n";
        
    }

    return 0;
}
