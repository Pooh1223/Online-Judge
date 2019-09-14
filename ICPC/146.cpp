#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	cout << (!(n % k) ? (n / k) : (n / k) + 1);
	return 0;
}