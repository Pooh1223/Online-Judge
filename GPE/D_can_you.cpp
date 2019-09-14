#include <bits/stdc++.h>
using namespace std;

long long nm[200003];

int main(){
	int cnt = 1;
	for(int i = 1;i < 200003;++i){
		nm[i] = nm[i - 1] + cnt++;
	}

	int t;
	cin >> t;
	for(int k = 1;k <= t;++k){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		cout << "Case " << k << ": ";
		cout << nm[c + d] + c - nm[a + b] - a << "\n";
	}

	return 0;
}