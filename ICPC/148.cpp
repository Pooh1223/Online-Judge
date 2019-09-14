#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	if(n < k || k == 0) cout << -1 << "\n";
	else if(k == 1){
		for(int i = 1;i <= n;++i) cout << i << " ";
		cout << "\n";
		for(int i = n;i >= 1;--i) cout << i << " ";
		cout << "\n";
	} else if(n == k){
		for(int i = 1;i <= n;++i) cout << i << " ";
		cout << "\n";
		for(int i = 1;i <= n;++i) cout << i << " ";
	} else {
		for(int i = 1;i <= n;++i) cout << i << " ";
		cout << "\n";
		for(int i = n - k + 1;i <= n;++i) cout << i << " ";
		for(int i = n - k;i >= 1;--i) cout << i << " ";
		cout << "\n";
	}
	return 0;
}