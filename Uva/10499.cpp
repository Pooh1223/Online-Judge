#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	while(cin >> n){
		if(n < 0) break;
		if(n == 1) cout << "0%\n";
		else cout << 25 * n << "%\n";
	}
	return 0;
}