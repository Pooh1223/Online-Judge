#include <bits/stdc++.h>
using namespace std;

double p[105],dp[10005];
int v[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	while(n--){
		double a;
		int b,sum = 0;
		cin >> a >> b;
		memset(dp,0,sizeof(dp));
		for(int i = 0;i < b;++i){
			cin >> v[i] >> p[i];
			sum += v[i];
		}
		dp[0] = 1.0;
		for(int i = 0;i < b;++i){
			for(int j = sum;j >= v[i];--j){
				double jizz = dp[j - v[i]] * (1.0 - p[i]);
				if(dp[j] < jizz) dp[j] = jizz;
			}
		}
		
		for(int i = sum;i >= 0;--i){
			if(dp[i] > (1 - a)){
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}