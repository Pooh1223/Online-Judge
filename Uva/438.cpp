#include <bits/stdc++.h>
using namespace std;

const double PI = 3.141592653589793;

inline double sq(double u){
	return u * u;
}

inline double dis(double x1,double y1,double x2,double y2){
	return sqrt(sq(x1 - x2) + sq(y1 - y2));
}

int main(){

	double x1,x2,x3,y1,y2,y3;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
		double a = dis(x1,y1,x2,y2);
		double b = dis(x3,y3,x2,y2);
		double c = dis(x1,y1,x3,y3);

		double da = acos((sq(b) + sq(c) - sq(a)) / 2 / b / c);

		printf("%.2lf\n",a / sin(da) * PI);
	}
	return 0;
}