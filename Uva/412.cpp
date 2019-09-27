#include <bits/stdc++.h>
using namespace std;

int num[103];

int main(){
	int n;
	while(~scanf("%d",&n) && n){
		for(int i = 0;i < n;++i) cin >> num[i];

		int cnt = 0;
		for(int i = 0;i < n;++i){
			for(int j = i + 1;j < n;++j){
				if(__gcd(num[i],num[j]) == 1) cnt++;
			}
		}

		if(cnt == 0){
			printf("No estimate for this data set.\n");
			continue;
		}

		double b = (double(n) * double(n - 1) / 2.0);
		printf("%.6lf\n",sqrt(6.0 * b / double(cnt)));
	}
	return 0;
}