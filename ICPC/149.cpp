#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
	long long n;
	int k = 9;
	cin >> n;
	if(n < 10){
		cout << n;
	} else {
		v.clear();
		while(k >= 2){
			if(n % k == 0){
				n /= k;
				v.push_back(k);
			} else {
				k--;
			}
		}
		if(n > 9) cout << -1;
		else {
			while(!v.empty()){
				cout << v.back();
				v.pop_back();
			}
		}
	}
	return 0;
}