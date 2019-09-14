#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	long long dp[100];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i = 0;i < n;i++){
		dp[i + 1] = dp[i] << 1;
	}
	for(int i = n;i < m;i++){
		for(int j = i;j > i - n - 1;--j){
			dp[i + 1] += dp[j];
		}
	}	
	cout << dp[m] << endl; 
	return 0;
} 
