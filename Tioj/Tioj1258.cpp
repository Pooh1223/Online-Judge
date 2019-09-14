#include <iostream>
#include <string>
using namespace std;

int gcd(int a,int b){
	int n = 0;
	while(1){
		if(a < b) swap(a,b);
		a -= b;
		n++;
		if(!a || !b) return n;
	}
}

int main(){
	int a,b;
	while(cin >> a >> b){
		cout << gcd(a,b) << endl;
	}
	return 0;
} 
