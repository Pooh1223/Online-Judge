#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

int main(){
	prime.push_back(2);
	for(int i = 3;i < 32768;++i){
		bool ok = 1;
		for(int j = 2;j < i;++j){
			if(!(i % j)){
				ok = 0;
				break;
			}
		}
		if(ok) prime.push_back(i);
	}

	int n;
	
	while(cin >> n && n){
		int cnt = 0;
		for(int i = 0;i < prime.size();++i){
			if(prime[i] > n / 2) break;
			for(int j = 0;j < prime.size();++j){
				if(prime[j] > n - prime[i]) break;
				if(prime[j] == n - prime[i]){
					cnt++;
					break;
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}