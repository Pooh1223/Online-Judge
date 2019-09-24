#include <bits/stdc++.h>
#define dd double
#define eps 1e-7
using namespace std;

dd calc(dd a,dd b,dd c,dd d,dd e,dd f,dd x){
	return a * exp(-x) + b * sin(x) + c * cos(x) + d * tan(x) + e * x * x + f;
}

int main(){
	dd p,q,r,s,t,u;
	while(~scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)){
		dd l = 0,rr = 1;
		if(calc(p,q,r,s,t,u,0) * calc(p,q,r,s,t,u,1) > 0){
			printf("No solution\n");
		} else {
			bool ok = 0;
			while(rr - l > eps){
				dd m = (l + rr) / 2.0;
				dd ans = calc(p,q,r,s,t,u,m);

				if(abs(ans) < eps){
					ok = 1;
					printf("%.4lf\n",m);
					break;
				} else if(ans > 0){
					l = m;
				} else {
					rr = m;
				}
				//printf("ans : %lf\n",ans);
			}
			if(!ok){
				printf("%.4lf\n",rr);
			}
		}
	}
	return 0;
}