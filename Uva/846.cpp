#include <bits/stdc++.h>
using namespace std;

long long dp[100003];

int main(){
	fstream f;
	f.open("output.txt",ios::out|ios::trunc);

	dp[1] = 1;
	for(int i = 2;i < 100003 && dp[i - 1] < 2147483648;++i){
		dp[i] = dp[i - 1] + (i + 1) / 2;
	}
	
	int n;
	cin >> n;
	while(n--){
		long long a,b;
		cin >> a >> b;
		long long m = b - a;

		if(a == b){
			cout << "0\n";
			continue;
		}

		for(int i = 1;;++i){
			if(dp[i] >= m){
				//cout << dp[i] << " ";
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}