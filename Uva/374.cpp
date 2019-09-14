#include <bits/stdc++.h>
using namespace std;

long long rec(int i,int j,int k){
	if(j == 1) return i % k;
	if(!j) return 1;

	long long a = rec(i,j / 2,k) % k;

	if(j % 2){
		return ((i % k) * a * a) % k;
	} else {
		return (a * a) % k;
	}
}

int main(){

	long long b,p,m;

	while(cin >> b >> p >> m){
		b = b % m;
		cout << rec(b,p,m) << "\n";
	}

	return 0;
}