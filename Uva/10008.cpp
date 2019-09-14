#include <bits/stdc++.h>
using namespace std;

int num[26];

int main(){
	int t;
	cin >> t;
	string s;
	while(getchar() != '\n');

	while(t--){
		
		getline(cin,s,'\n');

		for(int i = 0;i < s.length();++i){
			if((s[i] - 'a') >= 0 && (s[i] - 'a') <= 25) num[s[i] - 'a']++;
			else if((s[i] - 'A') >= 0 && (s[i] - 'A') <= 25) num[s[i] - 'A']++;
		}
	}
	int mx = -1,mn = 1e9;
	for(int i = 0;i < 26;++i){
		mx = max(num[i],mx);
		if(num[i] && num[i] < mn) mn = num[i];
	} 

	while(mx != mn - 1){
		for(int i = 0;i < 26;++i){
			if(num[i] == mx) cout << (char)(i + 'A') << " " << num[i] << "\n";
		}
		
		mx--;
	}

	return 0;
}