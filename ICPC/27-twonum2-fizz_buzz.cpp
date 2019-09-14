#include <cstdio>
using namespace std;
#define ll long long

int main(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	ll num = 0;
	num += (2 * (1000000000 / a)) + (2 * (1000000000 / b));
	printf("%lld",num);
	return 0;
}