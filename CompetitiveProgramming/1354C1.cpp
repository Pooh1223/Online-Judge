#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        int n;
        scanf("%d",&n);

        double r = 0.0;
        
        r = (1 / sin(PI / (2 * n)));

        printf("%.10lf\n",sqrt(r * r - 1.0));
    }

    return 0;
}
