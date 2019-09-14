#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 1;i < s.length();++i){
		int j = i - 1;
		while(s[j] == '.' && j >= 0) j--;;
		if(s[j] == s[i]){
			cnt++;
			s[i] = '.';
			s[j] = '.';
		}
	}
	if(cnt % 2) cout << "Yes\n";
	else cout << "No\n";
	
	return 0;
}