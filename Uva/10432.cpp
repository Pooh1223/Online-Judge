#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int main(){
	double a,b;
	while(~scanf("%lf %lf",&a,&b)){
		double one = a * a * sin(2 * PI / b) * 0.5;
		printf("%.3lf\n",one * b);
	}
	return 0;
}