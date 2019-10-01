#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		long long nm = 0;
		cin >> n;
		for(int i = 0;i < n;++i){
			long long a;
			cin >> a;
			nm += a;
		}
		if(!(nm % n)) cout << nm / n << "\n";
		else cout << nm / n + 1 << "\n";
	}
	return 0;
}