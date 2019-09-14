#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int l,r,d;
		cin >> l >> r >> d;
		if(d < l) cout << d << "\n";
		else cout << r + (d - (r % d)) << "\n";
	}
	return 0;
}