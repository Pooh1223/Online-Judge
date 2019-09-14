#include <iostream>
using namespace std;
#define ll long long
/*ll gcd(ll a,ll b){
	if(a < b) swap(a,b);
	while(1){
		a = a - b;
		if(a == 0) return b;
		if(b > a) swap(a,b);
	}
}*/
ll gcd(ll a,ll b){
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}
int main(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld",gcd(a,b));
	return 0;
}