#include <bits/stdc++.h>
using namespace std;

void gcd(long long a,long long b){
	if(!b){
		cout << "1 0 " << a << "\n";
		return;
	}
	long long oa = a,ob = b;
	long long s0 = 1,s1 = 0;
	long long t0 = 0,t1 = 1;
	int cnt = 0;

	while(a != 0){
		if(a < b) swap(a,b);
		
		if(cnt % 2){
			s1 = s1 - (a / b) * s0;
			t1 = t1 - (a / b) * t0;
		} else {
			s0 = s0 - (a / b) * s1;
			t0 = t0 - (a / b) * t1;
		}
		a = a % b;
		cnt++;
	}
	if(cnt % 2){
		if(oa * s1 + ob * t1 == b) cout << s1 << " " << t1;
		else cout << t1 << " " << s1;
	} else {
		if(oa * s0 + ob * t0 == b) cout << s0 << " " << t0;
		else cout << t0 << " " << s0;
	}
	cout << " " << b << "\n";
}

int main(){
	long long a,b;
	while(cin >> a >> b){
		gcd(a,b);
	}
	return 0;
}