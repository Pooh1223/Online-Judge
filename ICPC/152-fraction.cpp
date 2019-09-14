#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	if((a < 0 && b < 0) || (a > 0 && b > 0)){ // a / b is positive 
		if((c < 0 && d < 0) || (c > 0 && d > 0)){
			a = abs(a),b = abs(b),c = abs(c),d = abs(d);
			if(a * d > c * b) cout << ">\n";
			else if(a * d < c * b) cout << "<\n";
			else cout << "=\n";
		}
		else cout << ">\n";
	} else { // a / b is negative
		if((c < 0 && d < 0) || (c > 0 && d > 0)) cout << "<\n";
		else {
			a = abs(a),b = abs(b),c = abs(c),d = abs(d);
			if(a * d > c * b) cout << "<\n";
			else if(a * d < c * b) cout << ">\n";
			else cout << "=\n";
		}
	}
	return 0;
}