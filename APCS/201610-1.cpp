#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int d[3];
int main(){
	//int a,b,c;
	cin >> d[0] >> d[1] >> d[2];
	sort(d,d + 3);
	a = d[0]; b = d[1]; c = d[2];
	cout << a << " " << b << " " << c << "\n";
	if(a + b <= c){
		cout << "No\n";
	} else if(a * a + b * b == c * c ){
		cout << "Right\n";
	} else if(a * a + b * b < c * c) {
		cout << "Obtuse\n";
	} else {
		cout << "Acute\n";
	}

	return 0;
}