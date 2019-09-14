#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		long long num;
		cin >> num;
		num *= 63;
		num += 7492;
		num *= 5;
		num -= 498;
		num /= 10;
		cout << abs(num % 10) << "\n";
	}
	return 0;
}