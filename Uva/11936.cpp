#include <bits/stdc++.h>
using namespace std;

bool check(int a,int b,int c){
	if(a < 0 || b < 0 || c < 0) return 0;
	if(abs(a - b) >= c) return 0;
	if(a + b <= c) return 0;

	return 1;
}

int main(){
	int n;
	cin >> n;
	while(n--){
		int a,b,c;
		cin >> a >> b >> c;
		if(check(a,b,c) && check(b,c,a) && check(c,a,b)){
			cout << "OK\n";
		} else {
			cout << "Wrong!!\n";
		}
	}
	return 0;
}