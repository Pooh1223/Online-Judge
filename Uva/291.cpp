#include <bits/stdc++.h>
using namespace std;

bool used[7][7];
vector<int> v[7];
vector<int> ans;

void buildGragh(){
    v[1].push_back(2);
    v[1].push_back(3);
    v[1].push_back(5);

    v[2].push_back(1);
    v[2].push_back(3);
    v[2].push_back(5);

    v[3].push_back(1);
    v[3].push_back(2);
    v[3].push_back(4);
    v[3].push_back(5);

    v[4].push_back(3);
    v[4].push_back(5);

    v[5].push_back(1);
    v[5].push_back(2);
    v[5].push_back(3);
    v[5].push_back(4);
}

void go(int u,int d){
    if(d == 9){
        for(int i = 0;i < ans.size();++i) cout << ans[i];
        cout << "\n";
        return;
    }

    for(int i = 0;i < v[u].size();++i){
        if(!used[u][v[u][i]]){

            used[u][v[u][i]] = 1;
            used[v[u][i]][u] = 1;
            ans.push_back(v[u][i]);

            go(v[u][i],d + 1);

            ans.pop_back();
            used[u][v[u][i]] = 0;
            used[v[u][i]][u] = 0;
        }
    }
}

int main(){
    
    buildGragh();
    
    ans.push_back(1);
    go(1,1);

    return 0;
}
