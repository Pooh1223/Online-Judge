#include <iostream>
using namespace std;

int GCD(int x,int y){
	while(1){
		x %= y;
		if(x) y %= x;
		if(!x) return y;
		else if(!y) return x;
	}
}

int main(){
	int x,y;
	cout << "Please input two numbers." << endl;
	cin >> x >> y;
	cout << "The Greatest Common Divisor of these two numbers is " << GCD(x,y) << ".";
	return 0;
}
