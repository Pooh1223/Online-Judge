#include <bits/stdc++.h>
using namespace std;

int num[503];

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		for(int i = 0;i < n;++i) cin >> num[i];
		sort(num,num + n);

		if(n % 2){
			int mid = num[n / 2],sum = 0;
			for(int i = 0;i < n;++i) sum += abs(mid - num[i]);
			cout << sum << "\n";
		} else {
			int lmid = num[n / 2 - 1];
			int rmid = num[n / 2];
			int lsum = 0,rsum = 0;
			for(int i = 0;i < n;++i){
				lsum += abs(lmid - num[i]);
				rsum += abs(rmid - num[i]);
			}
			cout << min(lsum,rsum) << "\n";
		}	
	}
	
	return 0;
}