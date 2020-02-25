#include <bits/stdc++.h>
using namespace std;

vector< pair<int,int> > v[103];
int d[103];

int main(){
    int n,cnt = 1;

    while(cin >> n && n){

        for(int i = 0;i < 103;++i){
            d[i] = 1e9;
            v[i].clear();
        }

        int st;
        cin >> st;
        d[st] = 0;

        while(1){
            int a,b;
            cin >> a >> b;
            if(!a && !b) break;
            v[a].push_back(make_pair(b,-1));
        }

        for(int k = 0;k < n - 1;++k){
            for(int i = 1;i <= n;++i){
                for(int j = 0;j < v[i].size();++j){
                    int to = v[i][j].first;
                    int w = v[i][j].second;

                    if(d[i] + w < d[to]){
                        d[to] = d[i] + w;
                    }
                }
            }
        }

        int mn = 100;
        int pos = 0;

        for(int i = 1;i <= n;++i){
            if(mn > d[i]){
                mn = d[i];
                pos = i;
            }
        }

        cout << "Case " << cnt++ << ": The longest path from " << st;
        cout << " has length " << -mn << ", finishing at " << pos << ".\n\n";
    }

    return 0;
}
