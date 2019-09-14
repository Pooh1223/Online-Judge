#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		long long sum = 0;
		long long a,b,c,t;
		cin >> t;
		while(t--){
			cin >> a >> b >> c;
			sum += a * c;
		}
		cout << sum << "\n";
	}
	
	return 0;
}