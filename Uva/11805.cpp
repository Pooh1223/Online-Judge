#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 1;i <= t;++i){
		int n,k,p;
		cin >> n >> k >> p;
		cout << "Case " << i << ": " << ((k + p % n) % n == 0 ? n : (k + p % n) % n) << "\n";
	}
	return 0;
}