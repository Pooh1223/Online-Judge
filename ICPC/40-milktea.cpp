#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	cin.tie(0);
	//ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x,y,v;
		bool ck = 0;
		cin >> x >> y >> v;
		ll l = 0,r = 1e9;
		while(l < r){
			ll m = (l + r) / 2;
			//cout << "m : " << m << "\n";
			//system("pause");
			if((m + ((m / x) * y)) > v)
				r = m;
			else if((m + ((m / x) * y)) < v)
				l = m + 1;
			else {
				ck = 1;
				cout << "Possible\n";
				break;
			}
		}
		//cout << l << " " << r << "\n";
		if(!ck){
			if((l + ((l / x) * y)) != v) cout << "Impossible\n";
			else cout << "Possible\n";
		}
	}
	return 0;
}