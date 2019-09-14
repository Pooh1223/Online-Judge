#include <bits/stdc++.h>
using namespace std;

long long dp[200005][3];
const int mod = 1e9 + 7;

int main(){
	int n,l,r;
	cin >> n >> l >> r;

	int k0,k1,k2;
	k0 = r / 3 - (l % 3 ? l / 3 + 1: l / 3) + 1;
	k1 = (r - 1) / 3 - ((l - 1) % 3 ? ((l - 1) / 3 + 1): (l - 1) / 3) + 1;
	k2 = (r - 2) < 0 ? 0 : ((r - 2) / 3) - ((l - 2) < 0 ? 0 : (l - 2) % 3 ? ((l - 2) / 3 + 1) : (l - 2) / 3) + 1;

	dp[1][0] = k0;
	dp[1][1] = k1;
	dp[1][2] = k2;

	//cout << "k0 : " << k0 << "\nk1 : " << k1 << "\nk2 : " << k2 << "\n";

	for(int i = 2;i <= n;++i){
		dp[i][0] = ((dp[i - 1][0] * k0) + (dp[i - 1][1] * k2) + (dp[i - 1][2] * k1)) % mod; 
		dp[i][1] = ((dp[i - 1][0] * k1) + (dp[i - 1][1] * k0) + (dp[i - 1][2] * k2)) % mod;
		dp[i][2] = ((dp[i - 1][0] * k2) + (dp[i - 1][1] * k1) + (dp[i - 1][2] * k0)) % mod;
	}

	cout << dp[n][0];

	return 0;
}