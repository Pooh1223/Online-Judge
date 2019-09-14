#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if(n % 4 == 0) cout << n / 2 - 1 << " " << n / 2 + 1 << "\n";
	else if(n % 2 == 0) cout << n / 2 - 2 << " " << n / 2 + 2 << "\n";
	else cout << n / 2 << " " << n / 2 + 1 << "\n";
	return 0;
}