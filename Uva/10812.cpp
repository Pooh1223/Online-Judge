#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		long long a,b;
		cin >> a >> b;
		if(a % 2 ^ b % 2){
			cout << "impossible\n";
			continue;
		}
		long long x = (a + b) / 2;
		long long y = (a - b) / 2;
		if(x < 0 || y < 0) cout << "impossible\n";
		else cout << x << " " << y << "\n";
	}

	return 0;
}