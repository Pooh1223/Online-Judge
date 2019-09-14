#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,a,b;
		cin >> n;

		bitset<30> bit(n);
		cout << bit.count() << " ";

		stringstream ss;
		ss << n;
		ss >> hex >> n;
		bitset<30> bb(n);
		cout << bb.count() << "\n";
	}
	
	return 0;
}