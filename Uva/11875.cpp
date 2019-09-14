#include <bits/stdc++.h>
using namespace std;

int age[20];

int main(){
	int t;
	cin >> t;
	for(int k = 1;k <= t;++k){
		int n;
		cin >> n;
		for(int i = 0;i < n;++i) cin >> age[i];
		sort(age,age + n);
		cout << "Case " << k << ": " << age[n / 2] << "\n";
	}

	return 0;
}