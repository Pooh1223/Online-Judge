#include <bits/stdc++.h>
#define pi acos(-1)
using namespace std;

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        double n;
        scanf("%lf",&n);

        double red = n * n * 0.04 * pi;

        printf("%.2lf %.2lf\n",red,(n * 0.6 * n - red));
    }

    return 0;
}
