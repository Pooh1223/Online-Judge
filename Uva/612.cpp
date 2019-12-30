#include <bits/stdc++.h>
using namespace std;

struct array{
    int nm,id;
    bool operator<(const array &a)const{
        if(a.nm != nm) return a.nm > nm;
        return a.id > id;
    }
}ans[103];

int dna[103][103];
int bit[13];

int toNum(char c){
    if(c == 'A') return 1;
    else if(c == 'C') return 2;
    else if(c == 'G') return 3;
    else return 4;
}

char toChar(int n){
    if(n == 1) return 'A';
    else if(n == 2) return 'C';
    else if(n == 3) return 'G';
    else return 'T';
}

int lb(int x){return (x & -x);}

int sum(int x){
    int ans = 0;
    for(int i = x;i > 0;i -= lb(i)){
        ans += bit[i];
    }
    return ans;
}

void update(int x,int val,int n){
    for(int i = x;i <= n;i += lb(i)){
        bit[i] += val;
    }
}

int main(){
    int t;
    cin >> t;

    for(int tt = 0;tt < t;++tt){
        if(tt) cout << "\n";

        int len,m;
        cin >> len >> m;
        
        for(int i = 0;i < m;++i){
            ans[i].nm = 0;
            ans[i].id = i;

            for(int j = 0;j < 13;++j) bit[j] = 0;

            for(int j = 0;j < len;++j){
                char c;
                cin >> c;
                dna[i][j] = toNum(c);

                update(dna[i][j],1,4);
                
                ans[i].nm += (j + 1) - sum(dna[i][j]);
            }
        }

        sort(ans,ans + m);

        for(int i = 0;i < m;++i){
            for(int j = 0;j < len;++j){
                cout << toChar(dna[ans[i].id][j]);
            }
            cout << "\n";
        }
    }

    return 0;
}
