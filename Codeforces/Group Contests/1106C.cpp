#include <bits/stdc++.h>
using namespace std;

int num[300005];

int main(){

	int n;
	cin >> n;
	for(int i = 0;i < n;++i) cin >> num[i];
	sort(num,num + n);
	long long sum = 0;
	for(int i = 0;i < n / 2;++i){
		sum += pow(num[i] + num[n - i - 1],2.0);
	}
	cout << sum << "\n";
	
	return 0;
}