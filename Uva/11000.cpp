#include <bits/stdc++.h>
using namespace std;

long long m[1003],f[1003];

int main(){
	f[0] = 1;
	for(int i = 1;f[i - 1] + m[i - 1] <= 4294967296;++i){
		f[i] += m[i - 1] + 1;
		m[i] += m[i - 1] + f[i - 1];
	}

	long long n;
	while(cin >> n && n != -1){
		cout << m[n] << " " << m[n] + f[n] << "\n";
	}
	return 0;
}