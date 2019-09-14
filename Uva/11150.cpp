#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;

	while(cin >> n){
		if(!n) break;
		int a = n;
		int sum1 = 0,sum2 = 0,sum3 = 0;
		int emp = 0;

		while(n){
			int t = n + emp;
			sum1 += n;
			n = (n + emp) / 3;
			emp = t % 3;
		}
		
		emp = 1;
		n = a;
		while(n){
			int t = n + emp;
			sum2 += n;
			n = (n + emp) / 3;
			emp = t % 3;
		}
		if(emp >= 1) sum1 = max(sum1,sum2);
		emp = 2;
		n = a;
		while(n){
			int t = n + emp;
			sum3 += n;
			n = (n + emp) / 3;
			emp = t % 3;
		}
		if(emp >= 2) sum1 = max(sum1,sum3);
		
		cout << sum1 << "\n";
	}
	return 0;
}