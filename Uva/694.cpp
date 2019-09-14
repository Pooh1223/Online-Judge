#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long a,l;
	int cnt = 1;

	while(cin >> a >> l){
		if(a < 0 && l < 0) break;
		long long num = 0;

		cout << "Case " << cnt << ": A = " << a << ", limit = " << l 
		<< ", number of terms = ";

		while(1){
			if(a == 1){
				num++;
				break;
			}
			if(a % 2) a = a * 3 + 1;
			else a /= 2;
			num++;
			if(a > l) break;
		}

		cout << num << "\n";
		cnt++;
	}
	return 0;
}