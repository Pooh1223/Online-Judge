#include <bits/stdc++.h>
using namespace std;
bitset<20> s1,s2(8763);
int main(){
	s1[19] = 1;
	s1[17] = 1;
	s1[8] = 1;
	cout << (s1 != s2) << "\n";
	cout << (s1 & ~s2) << "\n";
	cout << (1 << 1) << "\n";
	cout << (1 << 0) << "\n";
	cout << (3 << 1) << "\n";
	cout << (1 << 3) << "\n";
	return 0;
}