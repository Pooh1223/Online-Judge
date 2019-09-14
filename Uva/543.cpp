#include <bits/stdc++.h>
using namespace std;

vector<int> v;

inline bool isPrime(int u){
	int l = 0,r = v.size() - 1;
	while(l < r){
		int m = (l + r) / 2;
		if(v[m] > u) r = m;
		else if(v[m] < u) l = m + 1;
		else return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	v.push_back(2);
	v.push_back(3);

	for(int i = 5;i < 1000000;i += 2){
		int num = sqrt(i) + 1;
		bool prime = 1;
		for(int j = 0;j < v.size();++j){
			if(v[j] > num) break;
			if(!(i % v[j])){
				prime = 0;
				break;
			}
		}
		if(prime) v.push_back(i);
	}

	while(cin >> n){
		if(!n) break;
		int a = 3,b = n - 3;
		bool out = 0;

		while(a <= n / 2){
			if(isPrime(a) && isPrime(b)){
				cout << n << " = " << a << " + " << b << "\n";
				out = 1;
				break;
			}
			a += 2;
			b -= 2;
		}
		if(!out) cout << "‘Goldbach's conjecture is wrong.\n";
	}

	return 0;
}