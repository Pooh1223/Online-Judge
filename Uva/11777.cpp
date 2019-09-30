#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int k = 1;k <= t;++k){
		int nm[10];
		for(int i = 0;i < 7;++i) cin >> nm[i];
		sort(nm + 4,nm + 7);

		double sum = 0.0;

		for(int i = 0;i < 4;++i) sum += nm[i];

		sum += ((double)nm[6] + (double)nm[5]) / 2.0;

		cout << "Case " << k << ": " ;//<< sum << " ";
		if(sum >= 90){
			cout << "A\n";
		} else if(sum >= 80){
			cout << "B\n";
		} else if(sum >= 70){
			cout << "C\n";
		} else if(sum >= 60){
			cout << "D\n";
		} else {
			cout << "F\n";
		}
	}
	return 0;
}