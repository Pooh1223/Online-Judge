#include <iostream>
#include <cstring>
using namespace std;

int multi(int);

int main(){
	int i;
	while(cin >> i)
		cout << multi(i) << endl;
	return 0;
}

int multi(int x){
	int dp[14];
	memset (dp , 0 ,sizeof(dp));
	if (x == 1) return 1;
	if (dp[x]) return dp[x];
	else return dp[x] = x * multi(x - 1);
}
