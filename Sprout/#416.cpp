#include <bits/stdc++.h>
using namespace std;
const int jizz = 1e9 + 7;
int n,a,b,k;
int dp[2005][2005];

int main(){
	cin.tie(0);
	cin >> n >> a >> b >> k;
	for(int i = 1;i <= b;++i) dp[i][0] = (b - i - 1) + (2 * i - b + 1) > 0 ? (b - i - 1) : (i - 1);
	for(int i = 1;i <= b;++i){
		for(int j = 1;j <= k;++j){
			dp[][k] = 
		}
	}
	return 0;
}