#include <bits/stdc++.h>
using namespace std;

long long dp[50];

int main(){
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 3;i < 50;++i){
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int t = 1,n;
	while(cin >> n){
		if(n < 48) cout << "case " << t++ << ":\n" << dp[n] << "\n\n";
		else cout << "case " << t++ << ":\n" << "overflow\n\n";
	}
	return 0;
}