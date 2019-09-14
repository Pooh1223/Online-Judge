#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	if((n - 1) % k == 0) cout << 2 * ((n - 1) / k) << "\n";
	else if((n - 1) % k == 1) cout << 2 * ((n - 1) / k) + 1 << "\n";
	else cout << 2 * ((n - 1) / k) + 2 << "\n";
	for(int i = 2;i <= n;++i){
		if(i <= 1 + k) cout << 1 << " " << i << "\n";
		else cout << i - k << " " << i << "\n";
	}
	return 0;
}