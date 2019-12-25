#include <bits/stdc++.h>
using namespace std;

char mp[33][33][33];
int dx[] = {0,0,1,-1,0,0};
int dy[] = {1,-1,0,0,0,0};
int dz[] = {0,0,0,0,1,-1};
int n,m,l;

struct node{
    int x,y,z,cnt;
};

bool boom(int x,int y,int z){
    return x < 0 || x >= l || y < 0 || y >= n || z < 0 || z >= m;
}

int main(){
    while(cin >> l >> n >> m){
        if(!l && !n && !m) break;
        
        int stx = 0,sty = 0,stz = 0;

        for(int i = 0;i < l;++i){
            for(int j = 0;j < n;++j){
                for(int k = 0;k < m;++k){
                    cin >> mp[i][j][k];
                    if(mp[i][j][k] == 'S'){
                        stx = i;
                        sty = j;
                        stz = k;
                    }
                }
            }
        }

        queue<node> q;
        q.push({stx,sty,stz,0});
        bool ok = 0;

        while(!q.empty() && !ok){
            node now = q.front();
            q.pop();
            
            for(int i = 0;i < 6;++i){
                int tx = now.x + dx[i];
                int ty = now.y + dy[i];
                int tz = now.z + dz[i];

                if(!boom(tx,ty,tz) && mp[tx][ty][tz] != '#'){
                    if(mp[tx][ty][tz] == 'E'){
                        cout << "Escaped in " << now.cnt + 1 << " minute(s).\n";
                        ok = 1;
                        break;
                    }    
                    mp[tx][ty][tz] = '#';
                    q.push({tx,ty,tz,now.cnt + 1});
                }
            }
        }

        if(!ok) cout << "Trapped!\n";
    }

    return 0;
}
