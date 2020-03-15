#include <bits/stdc++.h>
using namespace std;

struct counter{
    int id,cnt = 0;

    bool operator<(const counter& a)const{
        if(cnt != a.cnt) return cnt > a.cnt;
        return id < a.id;
    }

}nm[30];

char mp[1003][1003];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m;

bool boom(int x,int y){
    return x < 0 || y < 0 || x >= n || y >= m;
}

void bfs(int stx,int sty,char c){
    queue<int> xx;
    queue<int> yy;
    
    xx.push(stx);
    yy.push(sty);

    while(!xx.empty()){
        int x = xx.front();
        int y = yy.front();
        xx.pop();
        yy.pop();

        mp[x][y] = '.';

        for(int i = 0;i < 4;++i){
            int tx = x + dx[i];
            int ty = y + dy[i];

            if(!boom(x,y) && mp[tx][ty] == c){
                xx.push(tx);
                yy.push(ty);
            }
        }
    }
}

int main(){
    int t;
    cin >> t;

    for(int tt = 1;tt <= t;++tt){
        for(int i = 0;i < 30;++i){
            nm[i].id = i;
            nm[i].cnt = 0;
        }

        cin >> n >> m;

        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                cin >> mp[i][j];
            }
        }

        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if(mp[i][j] != '.'){
                    nm[mp[i][j] - 'a'].cnt++;
                    bfs(i,j,mp[i][j]);
                }
            }
        }

        sort(nm,nm + 30);
        
        cout << "World #" << tt << "\n";

        for(int i = 0;i < 30 && nm[i].cnt;++i){
            cout << char(nm[i].id + 'a') << ": " << nm[i].cnt << "\n";
        }
    }

    return 0;
}
