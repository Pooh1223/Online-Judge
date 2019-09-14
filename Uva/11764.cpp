#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;

	for(int k = 1;k <= t;++k){
		int n;
		cin >> n;
		int num[103];
		for(int i = 0;i < n;++i) cin >> num[i];
		int h = 0,l = 0;
		for(int i = 1;i < n;++i){
			if(num[i - 1] > num[i]) l++;
			else if(num[i - 1] < num[i]) h++;
		}
		cout << "Case " << k << ": " << h << " " << l << "\n";
	}

	return 0;
}