#include <bits/stdc++.h>
using namespace std;
int num[2][105];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int mx = 0;
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= i;++j){
			int jizz = max(num[i % 2][j],num[i % 2][j - 1]);
			cin >> num[!(i % 2)][j];
			num[!(i % 2)][j] += jizz;
			//cout << num[!(i % 2)][j] << " ";
			if(i == n) mx = max(mx,num[!(i % 2)][j]);
		}
		//cout << "\n";
	}
	cout << mx << "\n";
	return 0;
}