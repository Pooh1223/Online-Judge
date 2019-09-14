#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		int num = 1,cnt = 1;
		while(1){
			if(!num) break;
			if(num < n){
				num = num * 10 + 1;
				cnt++;
			} else {
				num = num - (num / n) * n;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}