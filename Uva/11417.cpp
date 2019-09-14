#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		long long sum = 0;
		for(int i = 1;i < n;++i)
			for(int j = i + 1;j <= n;++j)
				sum += __gcd(i,j);
		cout << sum << "\n";
	}
	return 0;
}