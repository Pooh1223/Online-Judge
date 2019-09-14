#include <iostream>
#include <cstring>
using namespace std;
int sum = 0;
int gg(long long num,long long a[]){
	if(num == 0) return 1;
	else if(num == 1) return 0;
	else if(num == 2) return 3;
	else if(num == 3) return 6;
	else if(a[num]) return a[num];
	for(int i = 2;num - i != 1;i++){
		sum += gg(i,a) * gg((num - i),a);
	}
	return a[num] = sum;
}

int main(){
	int n;
	cin >> n;
	long long time;
	long long dp[100000],x = n;
	memset(dp,0,sizeof(dp));
	dp[2] = 3; dp[3] = 6;
	while(n--){
		cin >> time;
		if(time == 0){
			cout << 0 << endl;
			continue; 
		}
		else if(time == 1){
			cout << 0 << endl;
			continue;
		}
		else if(time == 2){
			cout << 3 << endl;
			continue;
		}
		else if(time == 3){
			cout << 6 << endl;
			continue;
		}
		cout << ((time - 3) << 1) * 9 + gg(time,dp) << endl;
		sum = 0;
	}
	
	return 0;
}
