#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(false);
	cin.tie(0);
	double n;
	while(cin >> n){
		if(!n) break;
		if(sqrt(n) != (int)(sqrt(n))) cout << "no\n";
		else cout << "yes\n";
	}
	return 0;
}