#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;

	while(cin >> a >> b){
		if(!a && !b) break;
		int qa = sqrt(a),qb = sqrt(b);
		if(qa * qa == a) cout << qb - qa + 1; 
		else cout << qb - qa;
		cout << "\n";
	}
	
	return 0;
}