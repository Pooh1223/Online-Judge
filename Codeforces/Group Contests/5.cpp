#include <bits/stdc++.h>
using namespace std;

int main(){
	float f = 0.0;
	auto *ptr = (long*)(&(*(int*)(void*)(&f)));
	*ptr = 1048576000;
	cout << f << "\n";
	return 0;
}