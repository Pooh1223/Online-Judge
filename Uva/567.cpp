#include <bits/stdc++.h>
using namespace std;

vector<int> v[23];
bool used[23];

int bfs(int st,int ed){
    queue< pair<int,int> > q;
    used[st] = 1;
    q.push(make_pair(st,0));

    while(!q.empty()){
        int id = q.front().first;
        int d = q.front().second;

        q.pop();

        for(int i = 0;i < v[id].size();++i){
            if(v[id][i] == ed) return d + 1;

            if(!used[v[id][i]]){
                used[v[id][i]] = 1;
                q.push(make_pair(v[id][i],d + 1));
            }
        }
    }
}

int main(){
    int cnt = 1,fst;
    
    while(cin >> fst){

        for(int i = 0;i < 23;++i) v[i].clear();

        for(int i = 0;i < fst;++i){
            int k;
            cin >> k;
            v[1].push_back(k);
            v[k].push_back(1);
        }

        for(int i = 2;i <= 19;++i){
            int t;
            cin >> t;
            for(int j = 0;j < t;++j){
                int k;
                cin >> k;
                v[i].push_back(k);
                v[k].push_back(i);
            }
        }

        int q;
        cin >> q;
        
        cout << "Test Set #" << cnt++ << "\n";

        while(q--){
            memset(used,0,sizeof(used));

            int st,ed;
            cin >> st >> ed;

            printf("%2d to %2d: %d\n",st,ed,bfs(st,ed));
        }
        cout << "\n";
    }

    return 0;
}
