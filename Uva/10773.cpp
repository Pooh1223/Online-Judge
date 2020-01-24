#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);

    for(int k = 1;k <= n;++k){
        int d,v,u;
        cin >> d >> v >> u;
        
        if(v >= u){
            printf("Case %d: can't determine\n",k);
        } else if(!v || !u){
            printf("Case %d: can't determine\n",k); 
        } else {
            double sp,fp;
            sp = (double)d / (double)u;
            fp = (double)d / sqrt(double(u * u - v * v));
            printf("Case %d: %.3lf\n",k,abs(fp - sp));
        }
    }

    return 0;
}
