#include <cstdio>
#include <map>
#define ll long long
using namespace std;
const int Q = 1e9 + 7;
inline ll gcd(ll a,ll b){
	while(1){
		a %= b;
		if(!a) return b;
		b %= a;
		if(!b) return a;
	}
}
map<ll,ll> f;
ll fibo(ll n){
	if(f.count(n)) return f[n];
	ll k = n / 2;
	if(!(n % 2)) return f[n] = (fibo(k) * fibo(k) % Q + fibo(k - 1) * fibo(k - 1) % Q) % Q;
	else return f[n] = (fibo(k) * fibo(k + 1) % Q + fibo(k) * fibo(k - 1) % Q) % Q; 
}

int main(){
	ll a,b;
	scanf("%lld %lld",&a,&b);
	ll w = gcd(a + 1,b + 1) - 1;
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	printf("%lld\n",fibo(w));
	return 0;
}
