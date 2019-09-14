#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	string s;
	cin >> s;

	if(n == 1){

		cout << 0 << "\n" << s;

	} else if(n == 2){

		if(s[0] == s[1]){

			cout << 1 << "\n";
			if(s[0] == 'R') s[0] = 'G';
			else if(s[0] == 'G') s[0] = 'B';
			else if(s[0] == 'B') s[0] = 'R';
			cout << s;

		} else {
			cout << 0 << "\n" << s;
		}
	} else {
	
		string coms[2];

		for(int i = 0;i < n + 5;++i){
			if(i % 3 == 0){
				coms[0] += 'R';
				coms[1] += 'R';
			} else if(i % 3 == 1){
				coms[0] += 'B';
				coms[1] += 'G';
			} else {
				coms[0] += 'G';
				coms[1] += 'B';
			}
		}

		int cnt = 0,mn,a = 0,b = 0;

		for(int i = 0;i < 2;++i){
			for(int j = 0;j < 3;++j){
				for(int k = 0;k < n;++k){
					if(s[k] != coms[i][k + j]) cnt++;
				}
				if(i == 0 && j == 0) mn = cnt;
				else {
					if(mn > cnt){
						mn = cnt;
						a = i;
						b = j;
					}
				}
				cnt = 0;
			}
		}
		
		cout << mn << "\n";
		for(int i = 0;i < n;++i){
			cout << coms[a][i + b];
		}
		cout << "\n";

		// cout << coms[0] << "\n";
		// cout << coms[1] << "\n";

	}

	return 0;
}