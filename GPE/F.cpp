#include <bits/stdc++.h>
using namespace std;

string f[5002];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	f[0] = "0";
	f[1] = "1";
	f[2] = "1";
	for(int i = 3;i <= 5000;++i){
		reverse(f[i - 1].begin(),f[i - 1].end());
		reverse(f[i - 2].begin(),f[i - 2].end());
		int carry = 0;
		for(int j = 0;j < f[i - 1].length();++j){
			int a = 0,b = f[i - 1][j] - '0';
			if(j < f[i - 2].length()) a = f[i - 2][j] - '0';

			f[i] += char((a + b + carry) % 10 + '0');

			if(a + b + carry >= 10) carry = 1;
			else carry = 0;
		}
		if(carry) f[i] += "1";
		reverse(f[i - 1].begin(),f[i - 1].end());
		reverse(f[i - 2].begin(),f[i - 2].end());
		reverse(f[i].begin(),f[i].end());
	} 

	int n;

	while(cin >> n){
		cout << "The Fibonacci number for " << n << " is " << f[n] << "\n";
	}

	return 0;
}
