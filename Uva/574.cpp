#include <bits/stdc++.h>
using namespace std;

struct Seq{
    int seqlen,seq[20];

    bool operator<(const Seq &a)const{
        for(int i = 0;i < min(a.seqlen,seqlen);++i){
            if(a.seq[i] != seq[i]) return a.seq[i] < seq[i];
        }
    }
    
    bool operator==(const Seq &a)const{
        if(a.seqlen != seqlen) return false;
        else {
            for(int i = 0;i < seqlen;++i){
                if(a.seq[i] != seq[i]) return false;
            }
            return true;
        }
    }

};

int nm[20];
bool used[20];
vector<int> ansv;
vector<Seq> ans;

void dfs(int t,int n,int d,int sum){
    if(sum == t){
        Seq tmp;
        tmp.seqlen = ansv.size();

        for(int i = 0;i < ansv.size();++i){
            tmp.seq[i] = ansv[i];
        }
        
        bool same = 0;

        for(int i = 0;i < ans.size();++i){
            if(tmp == ans[i]){
                same = 1;
                break;
            }
        }
        
        if(!same){
            ans.push_back(tmp);
        }

        return;
    }

    for(int i = d;i < n;++i){
        if(!used[i] && sum + nm[i] <= t){

            used[i] = 1;
            ansv.push_back(nm[i]);
            sum += nm[i];

            dfs(t,n,i + 1,sum);

            used[i] = 0;
            ansv.pop_back();
            sum -= nm[i];
        }
    }
}

int main(){
    int t,n;
    while(cin >> t >> n){
        if(!t && !n) break;
        
        for(int i = 0;i < n;++i) cin >> nm[i];
        
        memset(used,0,sizeof(used));
        ansv.clear();
        ans.clear();

        dfs(t,n,0,0);
        
        sort(ans.begin(),ans.end());
        cout << "Sums of " << t << ":\n";
        if(ans.size() != 0){
            for(int i = 0;i < ans.size();++i){
                for(int j = 0;j < ans[i].seqlen;++j){
                    if(!j) cout << ans[i].seq[j];
                    else cout << "+" << ans[i].seq[j];
                }
                cout << "\n";
            }
        } else {
            cout << "NONE\n";
        }

    }
    return 0;
}
