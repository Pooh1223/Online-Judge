#include <bits/stdc++.h>
using namespace std;

bool prime[20000003];

int ans[100003];

int main(){
	for(int i = 0;i < 20000000;++i){
		prime[i] = true;
	}
	prime[1] = false;

	for(long long i = 2;i < 20000003;++i){
		if(prime[i]){
			for(long long j = i * i;j < 20000000;j += i){
				prime[j] = false;
			}
		}
	}

	int cnt = 0;
	for(int i = 3;i < 20000000 && cnt < 100000;i += 2){
		if(prime[i] && prime[i + 2]){
			ans[cnt++] = i;
		}
	}

	int n;
	while(cin >> n){
		cout << "(" << ans[n - 1] << ", " << ans[n - 1] + 2 << ")\n";
	}

	return 0;
}