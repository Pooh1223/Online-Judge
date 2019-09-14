#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	string s;
	cin >> n >> s;

	int st = 0,ed = 0,cnt = 1,chg = 0;
	//char now = s[0];

	for(int i = 0;i < n;++i){
		if(i + 1 < n && s[i] == s[i + 1]){
			cnt++;
		} else if(cnt != 1){

			ed = st + cnt - 1;

			if(cnt % 2){ //odd
				for(int j = st + 1;j < ed;j += 2){
					if(s[st] == 'R') s[j] = 'G';
					else s[j] = 'R'; 
				}
				chg += cnt / 2;
			} else { //even
				char c = s[st];
				for(int j = 1;j < (cnt / 2);++j){
					if(!(j % 2)) continue;
					if(s[st] == 'R'){
						s[st + j] = 'G';
						s[ed - j] = 'G';
					} else {
						s[st + j] = 'R';
						s[ed - j] = 'R';
					}
				}
				int d = cnt / 2 - 1;
				if(st + d == 0){ //BBXXXXXXX
					if(s[0] == 'R') s[0] = 'G';
					else s[0] = 'R';
				} else { //XXXBBXXXX
					if((int)(s[st + d - 1] + s[st + d + 1]) == 137) s[st + d] = 'R';
					else if((int)(s[st + d - 1] + s[st + d + 1]) == 148) s[st + d] = 'G';
					else if((int)(s[st + d - 1] + s[st + d + 1]) == 153) s[st + d] = 'B';
				}
				chg += cnt / 2;
			}

			st = i + 1;
			cnt = 1;
			//if(i + 1 < n) now = s[i + 1];
		} else {
			st++;
		}
	}

	cout << chg << "\n" << s;

	return 0;
}