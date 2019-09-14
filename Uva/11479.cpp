#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int k = 1;k <= t;++k){
		long long a,b,c;
		cin >> a >> b >> c;
		cout << "Case " << k << ": ";
		if(a + b <= c || b + c <= a || a + c <= b){
			cout << "Invalid\n";
		} else if(a == b && b == c){
			cout << "Equilateral\n";
		} else if(a == b || b == c || a == c){
			cout << "Isosceles\n";
		} else {
			cout << "Scalene\n";
		}
	}

	return 0;
}