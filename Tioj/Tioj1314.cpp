#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	int time;
	cin >> time;
	while(time--){
		cin >> a >> b >> c;
		if((a * a) + (b * b) == (c * c)||(c * c) + (b * b) == (a * a)||
		(a * a) + (c * c) == (b * b)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	
	return 0;
}
