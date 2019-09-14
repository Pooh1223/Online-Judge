#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	if(k == n){
		cout << 0 << " " << 0 << "\n";
	} else if(k > 0){
		if(k > n / 3){
			cout << 1 << " " << n - k << "\n";
		} else if(k < n / 3){
			cout << 1 << " " << k * 2 << "\n";
		} else {
			if(n % 3 == 0) cout << 1 << " " << n - k << "\n";
			else cout << 1 << " " << (n / 3) * 3 - k << "\n";
		}
	} else {
		cout << 0 << " " << 0 << "\n";
	}
	return 0;
}