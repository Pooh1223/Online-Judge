#include <bits/stdc++.h>
using namespace std;

long long dp[30003];
int cent[] = {1,5,10,25,50};

int main(){
	dp[0] = 1;
	for(int i = 0;i < 5;++i){
		for(int j = 1;j < 30001;++j){
			if(j - cent[i] >= 0) dp[j] += dp[j - cent[i]];
		}
	}

	int n;
	while(cin >> n){
		if(dp[n] == 1) cout << "There is only 1 way to produce " << n << " cents change.\n";
		else cout << "There are " << dp[n] << " ways to produce " << n << " cents change.\n";
	}

	return 0;
}