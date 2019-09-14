#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,ans;
	cin >> a >> b >> ans;
	stringstream ss;
	string s1,s2;
	ss << (ans / a);
	ss >> s1;
	ss.clear();
	ss << b;
	ss >> s2;
	if(s1.length() != s2.length()){
		cout << ans / b << " " << b << "\n";
	} else if(ans % a == 0) cout << a << " " << ans / a << "\n";
	else cout << ans / b << " " << b << "\n";
	return 0;
}