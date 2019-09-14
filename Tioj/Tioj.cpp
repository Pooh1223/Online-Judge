#include <iostream>
using namespace std;

int main(){
	double a,b;
	
	while(cin >> a >> b){
		if (a > b)
			cout << a;
		if (a < b)
			cout << b;
	}
	
	
	return 0;
}
