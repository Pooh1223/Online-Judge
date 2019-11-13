#include <bits/stdc++.h>
using namespace std;

int main(){
	double a,b,c;
	while(~scanf("%lf %lf %lf",&a,&b,&c)){
		double s = (a + b + c) / 2;
		double area = sqrt(s * abs(s - a) * abs(s - b) * abs(s - c));
		if(area / s != area / s) printf("The radius of the round table is: 0.000\n");
		else printf("The radius of the round table is: %.3lf\n",area / s);
	}
	return 0;
}