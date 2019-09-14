#include <bits/stdc++.h>
using namespace std;

int sum[102];

int main(){

	for(int i = 0;i < 101;++i){
		if(i){
			if(i % 2) sum[i] = sum[i - 1] + i;
			else sum[i] = sum[i - 1];
		}
	}

	int t;
	cin >> t;
	for(int i = 1;i <= t;++i){
		int a,b;
		cin >> a >> b;
		cout << "Case " << i << ": ";
		if(a) cout << sum[b] - sum[a - 1] << "\n";
		else cout << sum[b] << "\n";
	}
	return 0;
}