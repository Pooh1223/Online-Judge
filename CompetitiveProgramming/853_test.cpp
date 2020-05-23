#include<bits/stdc++.h>

using namespace std;

void add(vector<long long> &a, vector<long long> &b, vector<long long> &res) {
    for (int i = 0; i < a.size(); i++)
        res[i] = a[i] + b[i];
}

void sub(vector<long long> &a, vector<long long> &b, vector<long long> &res) {
    for (int i = 0; i < a.size(); i++)
        res[i] = a[i] - b[i];
}

void mul(vector<long long> &a, vector<long long> &b, vector<long long> &res) {
    if(a.size() == 1){
        res[0] = a[0] * b[0];
        res[1] = 0;
        return;
    }
    //if (a.size() <= 64) {
    //    for (int i = 0; i < a.size(); i++)
    //        for (int j = 0; j < b.size(); j++)
    //            res[i+j] += a[i]*b[j];
    //    return;
    //}
    int n = a.size();
    int h = n >> 1;
    vector<long long> ah(h), al(h), bh(h), bl(h);
    for (int i = 0; i < h; i++) {
        ah[i] = a[h+i];
        al[i] = a[i];
        bh[i] = b[h+i];
        bl[i] = b[i];
    }
    vector<long long> ahbh(n), albl(n), c(n);
    mul(ah, bh, ahbh);
    mul(al, bl, albl);
    // make ah to store ah+al and bh to bh+bl
    add(ah, al, ah);
    add(bh, bl, bh);
    mul(ah, bh, c);
    sub(c, ahbh, c);
    sub(c, albl, c);
    for (int i = 0; i < n; i++) res[i] += albl[i];
    for (int i = 0; i < n; i++) res[n+i] += ahbh[i];
    for (int i = 0; i < n; i++) res[h+i] += c[i];
}

int main() {
    int n, m, q;
    scanf("%d%d%d",&n,&m,&q);
    vector<long long> a(50004), b(50004), ans(100004);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    a[0]++;
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d",&x);
        b[x]++;
    }
    b[0]++;
    mul(a, b, ans);
    for(int i = 0; i < q; i++) {
        int x;
        scanf("%d",&x);
        printf("%lld\n", x > 100000 ? 0LL : ans[x]);
    }
    return 0;
}

