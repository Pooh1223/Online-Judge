#include <iostream>
#include <math.h>
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
	int a,b;
	while(cin >> a >> b){
		if (!a && !b) break;
		cout << GCD(a,b) << endl;
	}
	return 0;
}
