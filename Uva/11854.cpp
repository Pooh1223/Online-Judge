#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c;
	
	while(cin >> a >> b >> c){
		if(!a && !b && !c) break;

		if(a * a + b * b == c * c) cout << "right\n";
		else if(c * c + b * b == a * a) cout << "right\n";
		else if(a * a + c * c == b * b) cout << "right\n";
		else cout << "wrong\n";
	}

	return 0;
}