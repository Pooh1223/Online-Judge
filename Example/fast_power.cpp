#include <iostream>
using namespace std;
long long power(int a,int n){
	if(n == 1) return a;
	if(n & 1) return power(a,(n - 1) / 2) * power(a,(n - 1) / 2) * a;
	else return power(a,n / 2) * power(a,n / 2);
}
long long loop(int a,int n){
	int r = 1;
  	while(n){
	    if(n & 1) r *= a;
	    a *= a;
	    n >>= 1;
	 }
  return r;
}
int main(){
	int a,n;
	cout << "Please enter two numbers a and n.\nThis app can help you calculate a to the power of n.\n";
	cin >> a >> n;
	cout << "Recursive version : " << power(a,n) << '\n';
	cout << "Loop version : " << loop(a,n) << '\n';
	return 0;
}