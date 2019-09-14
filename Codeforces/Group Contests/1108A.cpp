#include <bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int l1,l2,r1,r2;
		cin >> l1 >> r1 >> l2 >> r2;
		cout << l1 << " ";
		if(l2 == l1) cout << l2 + 1 << "\n";
		else cout << l2 << "\n";
	}
	return 0;
}