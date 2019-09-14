#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isprime[5003];
void init(){
	for(int i = 0;i <= 5000;++i) isprime[i] = 1;
	isprime[0] = isprime[1] = 0;
	for(ll i = 2;i <= 5000;++i){
		if(isprime[i]){
			for(ll j = i * i;j <= 5000;j += i){
				isprime[j] = 0;
			}
		}
	}
}
int main(){
	cin.tie(0);
	init();
	int n;
	while(cin >> n){
		cout << "primes between 1 ~ " << n << ":";
		for(int i = 2;i <= n;++i) if(isprime[i]) cout << " " << i;
		cout << "\n";
	}
	return 0;
}