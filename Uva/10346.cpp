#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;

	while(cin >> n >> k){
		long long sum = n;

		while(n >= k){
			sum += n / k;
			n = n - (n / k) * k + (n / k);

		}

		cout << sum << "\n";
	}
	
	
	return 0;
}