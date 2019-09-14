#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		int mx = -1,mn = 10000;
		for(int i = 0;i < n;++i){
			int a;
			cin >> a;
			mx = max(mx,a);
			mn = min(mn,a);
		}
		cout << (mx - mn) * 2 << "\n";
	}

	return 0;
}