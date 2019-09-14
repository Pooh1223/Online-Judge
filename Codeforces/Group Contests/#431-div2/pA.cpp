#include <bits/stdc++.h>
using namespace std;
int num[105];
int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;++i) cin >> num[i];
	if(num[0] % 2 && num[n - 1] % 2 && n % 2 != 0) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}