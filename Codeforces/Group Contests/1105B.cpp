#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main(){
	int n,k;
	string s;

	cin >> n >> k >> s;
	s += '.';

	int len = 1;

	for(int i = 1;i <= n;++i){
		if(s[i - 1] == s[i]){
			len++;
		} else {
			cnt[s[i - 1] - 'a'] += len / k;
			len = 1;
		}
	}

	int mx = -1;
	for(int i = 0;i < 26;++i) mx = max(mx,cnt[i]);
		
	cout << mx << "\n";

	return 0;
}