#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int len;
		string s;
		cin >> len >> s;
		if(len > 2){
			cout << "YES\n2\n";
			cout << s[0] << " ";
			for(int i = 1;i < len;++i) cout << s[i];
			cout << "\n";
		} else {
			if(s[0] - s[1] >= 0) cout << "NO\n";
			else {
				cout << "YES\n2\n";
				cout << s[0] << " " << s[1] << "\n";
			}
		}
	}
	return 0;
}