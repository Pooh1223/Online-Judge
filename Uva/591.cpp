#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int cnt = 1;
	while(cin >> n){
		if(!n) break;
		//if(cnt != 1) cout << "\n";

		int num[103],sum = 0;
		for(int i = 0;i < n;++i){
			cin >> num[i];
			sum += num[i];
		}

		int avg = sum / n,ans = 0;

		for(int i = 0;i < n;++i) ans += abs(num[i] - avg);

		cout << "Set #" << cnt << "\n";
		cout << "The minimum number of moves is " << ans / 2 << ".\n\n";

		cnt++;
	}

	return 0;
}