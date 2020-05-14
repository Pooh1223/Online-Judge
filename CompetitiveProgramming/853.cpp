#include <bits/stdc++.h>
using namespace std;

void add(vector<long long> &a,vector<long long> &b,vector<long long> &c){
    for(int i = 0;i < a.size();++i){
        c[i] = a[i] + b[i];
    }
}

void sub(vector<long long> &a,vector<long long> &b,vector<long long> &c){
    for(int i = 0;i < a.size();++i){
        c[i] = a[i] - b[i];
    }
}

void mul(vector<long long> &a,vector<long long> &b,vector<long long> &c){
    /*if(a.size() == 1){
        c[0] = a[0] * b[0];
        c[1] = 0;
        return;
    }*/

    if(a.size() <= 32){
        for(int i = 0;i < a.size();++i){
            for(int j = 0;j < b.size();++j){
                c[i + j] += a[i] * b[j];
            }
        }
        return;
    }

    int n = a.size();
    int h = n >> 1;

    vector<long long> ah(h),al(h),bh(h),bl(h);
    
    for(int i = 0;i < h;++i){
        al[i] = a[i];
        ah[i] = a[h + i];
        bl[i] = b[i];
        bh[i] = b[h + i];
    }

    vector<long long> ahbh(n),albl(n),two(n);

    mul(ah,bh,ahbh);
    mul(al,bl,albl);

    add(ah,al,ah);
    add(bh,bl,bh);
    mul(ah,bh,two);

    sub(two,ahbh,two);
    sub(two,albl,two);

    for(int i = 0;i < n;++i){
        c[i] += albl[i];
    }
    for(int i = 0;i < n;++i){
        c[n + i] += ahbh[i];
    }
    for(int i = 0;i < n;++i){
        c[h + i] += two[i];
    }
}

int main(){

    vector<long long> a(65536),b(65536),c(1 << 17);

    for(int i = 0;i < 50004;++i){
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
        c[i + 50004] = 0;
    }

    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    //cin >> n >> m >> q;

    a[0] = 1;
    b[0] = 1;

    for(int i = 0;i < n;++i){
        int k;
        //cin >> k;
        scanf("%d",&k);
        a[k]++;
    }

    for(int i = 0;i < m;++i){
        int k;
        //cin >> k;
        scanf("%d",&k);
        b[k]++;
    }

    mul(a,b,c);
 
    for(int i = 0;i < q;++i){
        int k;
        //cin >> k;
        scanf("%d",&k);
        if(k > 100000){
            printf("0\n");
        } else printf("%lld\n",c[k]);
    }

    return 0;
}
