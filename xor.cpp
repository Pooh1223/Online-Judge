#include <bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	for(int i = 0;i < a.length();++i){
		cout << char(a[i] ^ b[i]);
	}
	return 0;
}