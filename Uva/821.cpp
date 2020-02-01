#include <bits/stdc++.h>
using namespace std;

vector<int> v[103];
bool used[103];
bool visit[103];

int bfs(int st,int ed){
    
    queue< pair<int,int> > q;

    q.push(make_pair(st,0));

    while(!q.empty()){
        int id = q.front().first;
        int d = q.front().second;

        q.pop();

        for(int i = 0;i < v[id].size();++i){
            if(v[id][i] == ed) return d + 1;

            q.push(make_pair(v[id][i],d + 1));
        }
    }
}

int main(){
    int ccnt = 1,pcnt = 0;
    int n,m;

    while(cin >> n >> m){
        if(!n && !m) break;
        
        for(int i = 0;i < 103;++i) v[i].clear();
        memset(used,0,sizeof(used));
        memset(visit,0,sizeof(visit));
        pcnt = 0;

        v[n].push_back(m);

        if(!used[n]){
            used[n] = 1;
            pcnt++;
        }

        if(!used[m]){
            used[m] = 1;
            pcnt++;
        }

        while(cin >> n >> m){
            if(!n && !m) break;
            
            v[n].push_back(m);

            if(!used[n]){
                used[n] = 1;
                pcnt++;
            }

            if(!used[m]){
                used[m] = 1;
                pcnt++;
            }

        }
        
        int toldep = 0;

        for(int i = 1;i <= 100;++i){
            if(used[i]){
                for(int j = 1;j <= 100;++j){
                    if(i != j && used[j]){
                        toldep += bfs(i,j);
                    }
                }
            }
        }

        cout << "Case " << ccnt++ << ": average length between pages = ";
        printf("%.3lf clicks\n",(double)toldep / (double)(pcnt * (pcnt - 1)));
    }

    return 0;
}
