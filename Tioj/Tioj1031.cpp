#include <iostream>
using namespace std;

int main(){
	int a,dp[25],k = 0;
	long long int sum = 0;
	dp[0] = 1;
	for(int i = 1;i < 25;i++){
		dp[i] = dp[i - 1] * 2;
	}
	while(1){
		cin >> a;
		if(a == 0){
			if(k == 0) break;
			cout << sum << endl;
			sum = 0;
			k = 0;
			continue;	
		} 
		for(int i = 0;i < 25;i++){
			if(dp[i] > a){
				a = dp[i - 1];
				sum += a;
				break;
			} 
		} 
		k++;
	}
	return 0;
} 
