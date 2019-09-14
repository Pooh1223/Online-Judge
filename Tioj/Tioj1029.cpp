#include <bits/stdc++.h>
using namespace std;
int num[1003],s[1003];
int dp[1003][1003];
int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;++i){
		cin >> num[i];
		s[i + 1] += num[i] + s[i];
		dp[i][i] = num[i];
	} 
	cout << dp[0][n - 1] << " " << s[n + 1] - dp[0][n - 1] << "\n";
	return 0;
}