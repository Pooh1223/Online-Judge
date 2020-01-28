#include <bits/stdc++.h>
using namespace std;

int main(){
    int type,cnt = 1;
    double u,v,t,s,a;

    while(~scanf("%d",&type)){

        if(type == 1){
            scanf("%lf %lf %lf",&u,&v,&t);
            a = (v - u) / t;
            s = (v + u) * t / 2;
            printf("Case %d: %.3lf %.3lf\n",cnt,s,a);
        } else if(type == 2){
            scanf("%lf %lf %lf",&u,&v,&a);
            t = (v - u) / a;
            s = (v + u) * t / 2;
            printf("Case %d: %.3lf %.3lf\n",cnt,s,t);
        } else if(type == 3){
            scanf("%lf %lf %lf",&u,&a,&s);
            t = max((-u + sqrt(u * u + 2 * a * s)) / a,(-u - sqrt(u * u + 2 * a * s)) / a);
            v = u + a * t;
            printf("Case %d: %.3lf %.3lf\n",cnt,v,t);
        } else if(type == 4){
            scanf("%lf %lf %lf",&v,&a,&s);
            t = ((v + sqrt(v * v - 2 * a * s)) / a,(v - sqrt(v * v - 2 * a * s)) / a);
            u = v - a * t;
            printf("Case %d: %.3lf %.3lf\n",cnt,u,t);
        } else break;

        cnt++;
    }
    return 0;
}
