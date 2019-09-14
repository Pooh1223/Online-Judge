#include <bits/stdc++.h>
using namespace std;

int main(){
	cout << "PERFECTION OUTPUT\n";

	int n;

	while(cin >> n){
		int sum = 1;
		int jizz = n;
		bool over = 0;

		if(!n){
			cout << "END OF OUTPUT\n";
			break;
		}

		if(n / 10000);
		else if(n / 1000) cout << " ";
		else if(n / 100) cout << "  ";
		else if(n / 10) cout << "   ";
		else cout << "    ";
		cout << n;

		if(n == 1){
			cout << "  DEFICIENT\n";
			continue;
		} 

		for(int i = 2;i < n;++i){
			if(sum > n){
				over = 1;
				cout << "  ABUNDANT\n";
				break;
			}
			if(!(n % i)){
				if(jizz == i) break;
				jizz = n / i;
				if(i != n / i) sum += i + n / i;
				else {
					sum += i;
					break;
				}
			}
		}
		if(!over){
			if(sum == n) cout << "  PERFECT\n";
			else if(sum < n) cout << "  DEFICIENT\n";
			else if(sum > n) cout << "  ABUNDANT\n";
		}
	}

	return 0;
}