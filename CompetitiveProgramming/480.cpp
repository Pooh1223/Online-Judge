#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll m;

void update(vector<vector<ll> > &v,int pos,ll nm,int mxh){
    int h = 0;
    v[h][pos] = nm % m;
    h++;

    while(h <= mxh){
        pos /= 2;
        v[h][pos] = v[h - 1][2 * pos] * v[h - 1][2 * pos + 1] % m;
        h++;
    }
}

ll query(vector<vector<ll> > &v,int h,int pos,int l,int r){
    int L = pos << h,R = (pos + 1) << h;
    int M = (L + R) / 2;

    if(L == l && R == r) return v[h][pos];
    if(l >= M) return query(v,h - 1,2 * pos + 1,l,r); //at right side
    if(r <= M) return query(v,h - 1,2 * pos,l,r); //at left side
    return query(v,h - 1,2 * pos,l,M) * query(v,h - 1,2 * pos + 1,M,r) % m;
}

ll inv(long long a,long long b){
    return 1 < a ? b - inv(b % a,a) * b / a : 1;
}

ll modinv(ll ans){
    if(__gcd(ans,m) != 1) return -1;
    else return inv(ans,m);
}

int main(){
    
    vector<vector<ll> > v(20,vector<ll>());

    for(int i = 0;i < 20;++i){
        v[i].resize(1 << (19 - i));
    }

    ll n,q;
    cin >> n >> q >> m;

    for(int i = 0;i < n;++i){
        cin >> v[0][i];
    }
    
    //build
    int mxh = 0;
    while((1 << mxh) < n) mxh++;

    for(int i = 1;i < 20;++i){
        for(int j = 0;j < v[i].size();++j){
            v[i][j] = v[i - 1][2 * j] * v[i - 1][2 * j + 1] % m;
        }
    }

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int l,r;
            cin >> l >> r;
            l--;

            ll ans = query(v,mxh,0,l,r);
            cout << modinv(ans) << "\n";
        } else {
            int x;
            ll nm;
            cin >> x >> nm;
            x--;

            update(v,x,nm,mxh);
        }
    }

    return 0;
}
