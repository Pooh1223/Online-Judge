#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s[2];
		cin >> s[0] >> s[1];

		for(int i = 0;i < 2;++i){
			for(int j = 0;j < n;++j){
				if(s[i][j] == '1' || s[i][j] == '2') s[i][j] = '0';
				else s[i][j] = '1';
			}
		}
		//0 -> line, 1 -> rect

		int x = 0,up = 0;
		bool ed = 0;
		while(x < n && !ed){
			if(!x){
				if(s[0][0] == '1' && s[1][0] == '0'){
					ed = 1;
					cout << "NO\n";
					break;
				} else if(s[0][0] == '0') up = 1;

			} else {
				if(up){
					if(s[0][x] == '1' && s[1][x] == '0'){
						ed = 1;
						cout << "NO\n";
						break;
					} else if(s[0][x] == '0') up = 1;
					else up = 0;
				} else {
					if(s[1][x] == '1' && s[0][x] == '0'){
						ed = 1;
						cout << "NO\n";
						break;
					} else if(s[1][x] == '1') up = 1;
				}
			}
			++x;
		}
		if(!ed){
			if(!up) cout << "YES\n";
			else cout << "NO\n";
		} 
	}
	return 0;
}