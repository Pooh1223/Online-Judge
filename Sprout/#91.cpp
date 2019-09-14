#include <iostream>
using namespace std;
int ans[1000];
int main(){
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		bool ck = 0;
		unsigned long long num;
		int n = 0;
		cin >> num;
		if(num < 10){
			ans[n++] = num;
			ck = 1;
		} 
		else{
			while(1){
				bool ck2 = 0;
				for(int i = 9;i >= 2;--i){
					if(num % i == 0) ck2 = 1;
				}
				if(!ck2) break;
				for(int i = 9;i >= 2;--i){
					if(num % i == 0){
						ans[n++] = i;
						num = num / i;
						ck = 1;
						break;
					}
				}
			}
		}
		if(!ck) cout << -1 << "\n";
		else if(ck && num < 10){
			for(int i = n - 1;i >= 0;--i) cout << ans[i];
			cout << "\n";
		}
		else cout << -1 << "\n";
	}
	return 0;
}