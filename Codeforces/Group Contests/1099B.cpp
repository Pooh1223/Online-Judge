#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long n;
	cin >> n;

	int l = 0,r = 1e9 + 2;

	if(n == 1) cout << "2\n";
	else {
		while(l < r){
			int mid = (l + r) / 2;
			long long x = mid / 2;
			//cout << "l : " << l << "\nr : " << r << "\nx = " << x << "\n";
			if(mid % 2){
				if(x * (x + 1) < n) l = mid + 1;
				else r = mid;
			} else {
				if(x * x < n) l = mid + 1;
				else r = mid;
			}
		}

		cout << l << "\n";
	}

	return 0;
}