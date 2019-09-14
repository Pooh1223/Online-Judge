#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	if(c == 0 && a == b) cout << "YES";
	else if(c == 0 && a != b) cout << "NO";
	else if(a == b) cout << "YES";
	else {
		int d = b - a;
		if((d > 0 && c > 0) ||(d < 0 && c < 0)){
			if(d % c == 0) cout << "YES";
			else cout << "NO";
		} else cout << "NO";
	}
	return 0;
}