#include <bits/stdc++.h>
using namespace std;

int main(){
	double a,b;
	while(~scanf("%lf %lf",&a,&b)){
		printf("%.50lf\n",pow(b,1.0 / a));
	}
	return 0;
}