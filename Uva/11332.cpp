#include <bits/stdc++.h>
using namespace std;

int main(){
	long long num;
	while(cin >> num){
		if(!num) break;
		int sum = 0;
		while(num >= 10){
			while(num){
				sum += num % 10;
				num /= 10;
			}
			num = sum;
			sum = 0;
		}
		cout << num << "\n";
	}
	return 0;
}