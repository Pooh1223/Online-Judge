#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;

	while(cin >> n){
		if(!n) break;
		long long num = sqrt(n);
		if(num * num == n) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}