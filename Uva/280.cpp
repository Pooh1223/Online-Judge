#include <bits/stdc++.h>
using namespace std;

bool used[103];
vector<int> v[103];

int bfs(int st){
    int cnt = 0;
    queue<int> q;
    
    for(int i = 0;i < v[st].size();++i) q.push(v[st][i]);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        if(used[u]) continue;
        
        cnt++;
        used[u] = 1;

        for(int i = 0;i < v[u].size();++i){
            if(!used[v[u][i]]){
                q.push(v[u][i]);
            }
        }
    }

    return cnt;
}

int main(){
    int n;
    while(cin >> n && n){
        
        for(int i = 0;i < 103;++i) v[i].clear();

        int a;
        while(cin >> a && a){
            int b;

            while(cin >> b && b){
                v[a].push_back(b);
            }
        }

        int q;
        cin >> q;

        while(q--){
            memset(used,0,sizeof(used));
            int st;
            cin >> st;

            cout << n - bfs(st);

            for(int i = 1;i <= n;++i){
                if(!used[i]) cout << " " << i;
            }

            cout << "\n";
        }
    }

    return 0;
}
