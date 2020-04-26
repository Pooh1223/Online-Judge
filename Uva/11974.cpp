#include <bits/stdc++.h>
using namespace std;

vector< bitset<16> > v;
unordered_set<bitset<16> > Set;

int bfs(int len,int step){
    bitset<16> ori("0000000000000000");
    
    queue<pair<bitset<16>,int> > q;
    q.push(make_pair(ori,0));
    
    Set.insert(ori);

    while(!q.empty()){
        bitset<16> now = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if(cnt > step){
            continue;
        }

        if(now.count() == len){
            return cnt;
        } else {
            for(int i = 0;i < v.size();++i){
                bitset<16> tmp = now ^ v[i];

                if(Set.count(tmp) == 0){
                    Set.insert(tmp);
                    q.push(make_pair(tmp,cnt + 1));
                }
            }    
        }
        
    }
    return -1;
}

int main(){
    int t;
    cin >> t;

    for(int tt = 1;tt <= t;++tt){
        v.clear();
        Set.clear();

        int n,m;
        cin >> n >> m;
        
        string s = "";

        for(int i = 0;i < m;++i){
            s = "";
            for(int j = 0;j < n;++j){
                char c;
                cin >> c;
                s += c;
            }
            bitset<16> bs(s);
            
            v.push_back(bs);
        }
        int ans = bfs(n,m);
        
        cout << "Case " << tt << ": ";
        if(ans != -1) cout << ans << "\n";
        else cout << "IMPOSSIBLE\n";
    }

    return 0;
}
