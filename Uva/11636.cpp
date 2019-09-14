#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,t = 1;
	while(cin >> n){
		if(n < 0) break;
		int cnt = 0;
		int num = 1;
		while(num < n){
			num *= 2;
			cnt++;
		}
		cout << "Case " << t++ << ": " << cnt << "\n";
	}
	return 0;
}