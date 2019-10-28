#include <bits/stdc++.h>
#define esp 1e-7
using namespace std;

int main(){
	long long h,one;
	while(cin >> h >> one){
		if(!h && !one) break;
		if(h == 1 && one == 1){
			cout << "0 1\n";
			continue;
		} else if(h - one == 1){
			cout << "1 " << h + one << "\n";
			continue;
		}

		int a = 1;

		while(abs(pow(h,1 / (double)a) - pow(one,1 / (double)a) - 1) > esp){
			a += 1;
		}

		long long sum = 0,cnt = 0;
		long long n = (pow(one,1 / (double)a) + 0.5),m = (pow(h,1 / (double)a) + 0.5);
		//cout << pow(h,1 / (double)a) << " , " << pow(one,1 / (double)a) << "\n";
		//cout << "a , n , m : " << a << " , " << n << " , " << m << "\n";

		for(int i = 0;i < a;++i){
			cnt += int(pow(n,i) + 0.5);
			sum += h * int((pow(n,i)) + 0.5);
			h /= m;
		}
		cout << cnt << " " << sum + one << "\n";
	}
	return 0;
}