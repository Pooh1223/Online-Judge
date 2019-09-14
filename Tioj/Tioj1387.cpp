#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	cin >> n;
	int w[n],v[n],num[n];
	for(int i = 0;i < n;i++){
		cin	>> w[i] >> v[i] >> num[i];
	}
	int W;
	cin >> W;
	int dp[W + 1];
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= n;i++){
		for(int k = 0;k < num[i - 1];k++){
			for(int j = w[i - 1];j <= W;j++){
				dp[j] = max(dp[j],dp[j - w[i - 1]] + v[i - 1]);
			}
		}
	}
	cout << dp[W] << endl;
	return 0;
}
