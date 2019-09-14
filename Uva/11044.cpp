#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int m,n;
		cin >> n >> m;

		n -= 2;
		m -= 2;

		int a,b;
		a = n / 3;
		b = m / 3;
		if(n % 3) a += 1;
		if(m % 3) b += 1;
		cout << a * b << "\n";
	}
	
	return 0;
}