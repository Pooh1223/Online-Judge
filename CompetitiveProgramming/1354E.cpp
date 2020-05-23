#include <bits/stdc++.h>
using namespace std;

vector<int> v[5003],stp;
vector<pair<int,int>> bicnt;
bool past[5003][2];
int p1,p2,ansnm[5003];
int dp[5003][5003];
bool lastcheck[5003];
int n,m,n1,n2,n3;

void dfs(int u){

    for(int i = 0;i < v[u].size();++i){
        int now = v[u][i];
        
        if(past[now][0] || past[now][1]){
            if(past[now][0]){
                if(past[u][0]){
                    cout << "NO\n";
                    exit(0);
                }
            } else {
                if(past[u][1]){
                    cout << "NO\n";
                    exit(0);
                }
            }
        } else {
            if(past[u][0]){
                past[now][1] = 1;
                p1++;
                dfs(now);
            } else {
                past[now][0] = 1;
                p2++;
                dfs(now);
            }
        } 
    }

}

int main(){
    cin >> n >> m >> n1 >> n2 >> n3;
    
    for(int i = 0;i < m;++i){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }    

    //check if it is a binary graph
    
    for(int i = 1;i <= n;++i){
        if(!past[i][0] && !past[i][1]){
            p1 = 0;
            p2 = 0;

            past[i][0] = 1;
            p2++;
            dfs(i);
            
            bicnt.push_back(make_pair(p1,p2));
            stp.push_back(i);
            
        }
    } 

    dp[0][0] = -1;

    for(int i = 0;i < bicnt.size();++i){
        for(int j = 0;j <= 5000;++j){

            if(dp[i][j] && j + bicnt[i].first <= 5000){
                dp[i + 1][j + bicnt[i].first] = -1;
            }

            if(dp[i][j] && j + bicnt[i].second <= 5000){
                dp[i + 1][j + bicnt[i].second] = 1;
            } 

        }
    }

    int sz = bicnt.size();
    
    if(dp[sz][n2]){
        cout << "YES\n";
        int tmp = n2;
        
        vector<int> ans;

        for(int i = sz;i >= 1;--i){
            int l = bicnt[i - 1].first,r = bicnt[i - 1].second;

            if(dp[i][tmp] == -1){
                tmp -= l;
                ans.push_back(l);
            } else if(dp[i][tmp] == 1){
                tmp -= r;
                ans.push_back(r);
            }
        }
        
        int cnt = 0;
        while(!ans.empty()){
            int c2 = ans.back();
            ans.pop_back();

            queue<pair<int,int>> q;
            
            if(c2 == bicnt[cnt].first){
                if(n1 != 0){
                    q.push(make_pair(stp[cnt],1));
                    n1--;
                } else {
                    q.push(make_pair(stp[cnt],3));
                    n3--;
                }
                
                lastcheck[stp[cnt]] = 1;
                cnt++;
            } else {
                q.push(make_pair(stp[cnt],2));
                
                lastcheck[stp[cnt]] = 1;
                cnt++;
            }

            while(!q.empty()){
                int u = q.front().first;
                int color = q.front().second;

                q.pop();

                ansnm[u] = color;

                for(int i = 0;i < v[u].size();++i){
                    int now = v[u][i];
                    if(!lastcheck[now]){
                        lastcheck[now] = 1;

                        if(color == 2){
                            if(n1 != 0){
                                q.push(make_pair(now,1));
                                n1--;
                            } else {
                                q.push(make_pair(now,3));
                                n3--;
                            }
                        } else {
                            q.push(make_pair(now,2));
                        }
                    }
                }
            }
        }

        for(int i = 1;i <= n;++i) cout << ansnm[i];
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
