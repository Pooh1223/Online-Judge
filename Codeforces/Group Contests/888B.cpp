#include <bits/stdc++.h>
using namespace std;
int r,l,u,d;
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0;i < n;++i){
		if(s[i] == 'R') r++;
		else if(s[i] == 'L') l++;
		else if(s[i] == 'U') u++;
		else if(s[i] == 'D') d++;
	}
	cout << 2 * (min(r,l) + min(u,d)) << "\n";
	return 0;
}