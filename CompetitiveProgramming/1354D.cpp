#include <bits/stdc++.h>
using namespace std;

int nm[1000003];
int n;

inline int lb(int x){
    return x & (-x);
}

void add(int x){
    while(x <= n){
        nm[x]++;
        x += lb(x);
    }
}

void rm(int x){
    while(x <= n){
        nm[x]--;
        x += lb(x);
    }
}

int query(int x){
    int sum = 0;
    while(x > 0){
        sum += nm[x];
        x -= lb(x);
    }
    return sum;
}

int main(){

    int q;
    scanf("%d %d",&n,&q);

    for(int i = 0;i < n;++i){
        int k;
        scanf("%d",&k);
        add(k);
    }

    while(q--){
        int com;
        scanf("%d",&com);

        if(com < 0){
            int l = 1,r = n;

            while(r - l >= 1){
                int m = (l + r) / 2;
                if(query(m) >= -com) r = m;
                else l = m + 1;
            }

            //cout << "remove : " << l << "\n";

            rm(l);
        } else {
            add(com);
        }

        //for(int i = 0;i <= n;++i){
        //    cout << "i : " << nm[i] << "\n";
        //}
    }

    for(int i = 1;i <= n;++i){
        if(query(i) != 0){
            printf("%d\n",i);
            return 0;
        }
    }

    printf("0\n");

    return 0;
}
