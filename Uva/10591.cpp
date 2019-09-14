#include <bits/stdc++.h>
using namespace std;

long long sqr[10] = {0,1,4,9,16,25,36,49,64,81};
set<long long> s;

int main(){
	int t;
	cin >> t;
	
	for(int i = 1;i <= t;++i){
		s.clear();
		long long nm;
		cin >> nm;

		cout << "Case #" << i << ": " << nm;
		
		while(1){
			long long sum = 0;

			while(nm){
				sum += sqr[nm % 10];
				nm /= 10;
			}

			if(sum == 1){
				cout << " is a Happy number.\n";
				break;
			}

			if(s.count(sum)){
				cout << " is an Unhappy number.\n";
				break;
			} else {
				s.insert(sum);
			}

			nm = sum;
		}

	}
	return 0;
}