#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int num[100005];
int main(){
	int n;
	while(cin >> n){
		if(n == EOF) break;
		memset(num,0,sizeof(num));
		if(n == 1){
			int a;
			cin >> a;
			cout << 0 << "\n";
			continue;
		}
		for(int i = 0;i < n;++i) cin >> num[i];
		sort(num,num + n);
		if(n % 2 == 0){
			int m1 = n / 2;
			int m2 = (n / 2) - 1;
			int ans = (num[m1] + num[m2]) / 2;
			int sum = 0;
			for(int i = 0;i < n;++i) sum += abs(num[i] - ans);
			cout << sum << "\n";
		}
		else{
			int m = n / 2;
			int sum = 0;
			for(int i = 0;i < n;++i) sum += abs(num[i] - num[m]);
			cout << sum << "\n";
		}
	}
	return 0;
}