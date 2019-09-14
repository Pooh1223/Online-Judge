#include <bits/stdc++.h>
using namespace std;

int dp[60];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;
	for(int i = 5;i < 55;++i){
		dp[i] = dp[i - 1] + dp[i - 3];
	}
	int n;
	while(cin >> n){
		if(!n) break;
		cout << dp[n] << "\n";
	}

	return 0;
}