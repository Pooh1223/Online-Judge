#include <bits/stdc++.h>
using namespace std;

long long cnt = 0;

void go(long long a){
	//cout << a << " ";
	cnt++;
	if(a == 1) return;
	else {
		if(a % 2) a = 3 * a + 1;
		else a /= 2;
		go(a);
	}
}

int main(){

	long long a,b,mx;
	while(cin >> a >> b){

		mx = 0;

		for(long long i = min(a,b);i <= max(a,b);++i){
			go(i);
			mx = max(mx,cnt);
			cnt = 0;
		}
		cout << a << " " << b << " " << mx << "\n";

	}

	return 0;
}
