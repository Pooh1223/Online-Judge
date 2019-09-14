#include <bits/stdc++.h>
using namespace std;
int t[100005];
int main(){
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 0;i < n;++i){
		int j;
		cin >> j;
		sum += j;
	}
	for(int i = 0;i < n;++i){
		cin >> t[i];
	}
	sort(t,t + n);
	long long vol = t[n - 1] + t[n - 2];
	if(n == 2) cout << "YES\n";
	else if(sum > vol) cout << "NO\n";
	else cout << "YES\n";
	return 0;
}