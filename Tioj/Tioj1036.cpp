#include <iostream>
using namespace std;
#define ll long long
int dp[10000003];
bool isprime[10000003];
void init(){
	int cnt = 0;
	for(int i = 0;i <= 10000000;++i) isprime[i] = 1;
	isprime[0] = isprime[1] = 0;
	dp[0] = dp[1] = 0;
	for(ll i = 2;i <= 10000000;++i){
		dp[i] = cnt + isprime[i];
		if(isprime[i]){
			++cnt;
			for(ll j = i * i;j <= 10000000;j += i){
				isprime[j] = 0;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	init();
	//cout << "jizz";
	while(n--){
		int m;
		cin >> m;
		cout << dp[m] << "\n";
	}
	return 0;
}