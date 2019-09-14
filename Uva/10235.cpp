#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

int main(){
	string ans = "";
	prime.push_back(2);
	for(int i = 3;i < 1000000;i += 2){
		bool ok = 1;
		for(int j = 2;j <= sqrt(i);++j){
			if(!(i % j)){
				ok = 0;
				break;
			}
		}
		if(ok) prime.push_back(i);
	}

	int n;
	while(cin >> n){
		string s = to_string(n);
		reverse(s.begin(),s.end());
		int num = stoi(s);

		int l = 0,r = prime.size() - 1;
		bool posi = 0,nega = 0;
		while(l <= r){
			int m = (l + r) / 2;
			if(prime[m] > n) r = m - 1;
			else if(prime[m] < n) l = m + 1;
			else {
				posi = 1;
				break;
			}
		}
		if(!posi && prime[l] != n){
			ans += to_string(n) + " is not prime.\n";//cout << n << " is not prime.\n";
			continue;
		}
		l = 0; r = prime.size() - 1;
		while(l <= r){
			int m = (l + r) / 2;
			if(prime[m] > num) r = m - 1;
			else if(prime[m] < num) l = m + 1;
			else {
				nega = 1;
				break;
			}
		}
		if((nega || prime[l] == num) && num != n) ans += to_string(n) + " is emirp.\n";//cout << n << " is emirp.\n";
		else ans += to_string(n) + " is prime.\n";//cout << n << " is prime.\n";
	}
	cout << ans;
	return 0;
}