#include <iostream>
using namespace std;

int main(){
	long double a,b;
	while(cin >> a >> b){
		if(!a && !b || a == b) break;
		if(a > b) cout << a << endl;
		else if(a < b) cout << b << endl;
	}
	return 0;
}
