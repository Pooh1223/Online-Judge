#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	while(n--){
		int t;
		int num[100],pos[100];
		int cnt = 0;
		cin >> t;
		for(int i = 0;i < t;++i) cin >> num[i];
		for(int i = 0;i < t;++i){
			for(int j = 0;j < t - i - 1;++j){
				if(num[j] > num[j + 1]){
					swap(num[j],num[j + 1]);
					cnt++;
				} 
			}
		}
		cout << "Optimal train swapping takes " << cnt << " swaps.\n";
	}

	return 0;
}