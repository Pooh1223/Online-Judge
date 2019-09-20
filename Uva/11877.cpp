#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		int cnt = 0;
		int left = 0;
		while(n){
			if(n == 1 || n == 2) break;
			cnt += n / 3;
			left = n % 3;
			n /= 3;
			n += left;
		}
		if(n == 2) cnt += 1;
		cout << cnt << "\n";
	}
	return 0;
}