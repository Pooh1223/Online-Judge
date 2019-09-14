#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		long long k,x;
		cin >> k >> x;
		if(k == 1) cout << x << "\n";
		else {
			cout << (long long)9 * (k - 1) + x << "\n";
		}
	}
	return 0;
}