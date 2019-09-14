#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 1;i <= t;++i){
		int n;
		cin >> n;
		int mx = -1;
		for(int j = 0;j < n;++j){
			int k;
			cin >> k;
			mx = max(mx,k);
		}
		cout << "Case " << i << ": " << mx << "\n";
	}
	
	return 0;
}