#include <bits/stdc++.h>
using namespace std;

long long sum;

int main(){
	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;
		if(s == "donate"){
			int money;
			cin >> money;
			sum += money;
		} else {
			cout << sum << "\n";
		}
	}

	return 0;
}