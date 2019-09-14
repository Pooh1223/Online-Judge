#include <iostream>
using namespace std;

int main(){
	long long a,b,c;
	int time;
	cin >> time;
	while(time--){
		cin >> a >> b >> c;
		if(a > 0 && b > 0 && c > 0 && ((a * a) + (b * b) == (c * c) || (b * b) + (c * c) == (a * a) || (a * a) + (c * c) == (b * b))){
			cout << "yes" << endl;
		}
		else cout << "no" << endl;
	}
	
	return 0;
}
