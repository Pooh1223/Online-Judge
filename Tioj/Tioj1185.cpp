#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long long a,b,c;
	while(cin >> a >> b >> c){
		if(abs(a - b) < c && a + b > c) printf("SAFE\n");
		else printf("BYE\n");
	}
	
	return 0;
}
