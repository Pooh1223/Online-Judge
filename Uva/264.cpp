#include <bits/stdc++.h>
using namespace std;

int num[4005];

int main(){
	int len = 1;
	for(;;++len){
		num[len] = len + num[len - 1];
		if(num[len] >= 10000000){
			len++;
			break;
		}
	}
	
	int n;
	while(cin >> n){
		
		if(n == 1){
			cout << "TERM 1 IS 1/1\n";
			continue;
		} 

		int pos = -1;
		for(int i = 2;i < len;++i){
			if(num[i] == n){
				if(i % 2) cout << "TERM " << n << " IS 1/" << i << "\n";
				else cout << "TERM " << n << " IS " << i << "/1\n";
				break;
			} else if(num[i - 1] + 1 <= n && n <= num[i]){
				pos = i - 1;
				break;
			}
		}
		if(pos == -1) continue;

		int x,y,drc;
		if(!(pos % 2)){
			x = pos + 1;
			y = 1;
			drc = 1;
		} else {
			x = 1;
			y = pos + 1;
			drc = -1;
		}
		int cnt = num[pos] + 1;
		while(cnt != n){
			x -= drc;
			y += drc;
			cnt++;
		}
		cout << "TERM " << n << " IS " << x << "/" << y << "\n";
	}

	return 0;
}