#include <bits/stdc++.h>
using namespace std;

int f91(int k){
	if(k <= 100) return f91(f91(k + 11));
	else if(k >= 101) return k - 10;
}

int main(){

	int n;
	while(cin >> n){
		if(!n) break;
		cout << "f91(" << n << ") = " << f91(n) << "\n";
	}

	return 0;
}