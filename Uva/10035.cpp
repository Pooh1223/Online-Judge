#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a,b;

	while(cin >> a >> b){
		if(!a && !b) break;
		int cnt = 0;
		bool carry = 0;
		while(a || b){
			if(a % 10 + b % 10 + carry >= 10){
				cnt++;
				carry = 1;
			} else carry = 0;
			a /= 10;
			b /= 10;
		}

		if(cnt == 0) cout << "No carry operation.\n";
		else if(cnt == 1) cout << "1 carry operation.\n";
		else cout << cnt << " carry operations.\n";
	}

	return 0;
}