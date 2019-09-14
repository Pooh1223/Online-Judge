#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a,b;
	while(cin >> a >> b){
		long long c = a,d = b;
		if(c > d) swap(a,b);
		int mx = -1;
		for(int i = a;i <= b;++i){
			int cnt = 0;
			long long n = i;
			while(n != 1){
				if(n % 2) n = 3 * n + 1;
				else n /= 2;
				cnt++;
			}
			mx = max(mx,cnt + 1);
		}
		cout << c << " " << d << " " << mx << "\n";
	}
	return 0;
}