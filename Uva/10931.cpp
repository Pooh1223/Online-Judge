#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	while(cin >> n && n){
		bitset<33> b(n);
		string s = "";
		bool st = 0;

		for(int i = b.size() - 1;i >= 0;--i){
			if(st) s += to_string(b[i]);
			else if(b[i] == 1 && !st){
				st = 1;
				s += to_string(b[i]);
			}
		}
		cout << "The parity of " << s << " is " << b.count() << " (mod 2).\n";
	}

	return 0;
}