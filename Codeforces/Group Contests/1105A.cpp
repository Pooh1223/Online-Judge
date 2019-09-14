#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,num[1005],t = 1,ans = 0,mx = -1;

	cin >> n;
	for(int i = 0;i < n;++i){
		cin >> num[i];
		mx = max(num[i],mx);
	}

	for(int i = 1;i <= mx;++i){
		int sum = 0;
		for(int j = 0;j < n;++j){
			if(num[j] > i) sum += num[j] - i - 1;
			else if(i > num[j]) sum += i - num[j] - 1;
		}
		if(i == 1) ans = sum;
		else if(sum < ans){
			ans = sum;
			t = i;
		}
	}

	cout << t << " " << ans << "\n";

	return 0;
}