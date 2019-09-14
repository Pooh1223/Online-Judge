#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[60];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	dp[0] = dp[1] = 1;
	for(int i = 2;i < 51;++i){
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int n;
	cin >> n;
	while(n--){
		int a,b;
		cin >> a >> b;
		cout << dp[b - a] << "\n";
	}
	
	return 0;
}