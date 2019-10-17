#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;

		int sum = 0;
		b += a;

		while(b >= c){
			sum += b / c;
			b = b / c + b % c;
		}

		cout << sum << "\n";
	}
	return 0;
}