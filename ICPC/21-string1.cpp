#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	int len,lid,rid,ans = 0;
	char l,r;
	bool st = 0;
	cin >> len >> s;
	for(int i = 0;i < len;++i){
		if(st == 0 && s[i] != '?'){
			l = s[i];
			lid = i;
			st = 1;
		} 
		else if(st == 1 && s[i] != '?'){
			r = s[i];
			rid = i;
			int cnt = rid - lid - 1;
			if(cnt == 0){
				l = r;
				lid = rid;
				continue;
			} 
			if(l == r){
				if(l == 'A' || l == 'B'){
					ans += 1 - (cnt % 2);
				}
			} else {
				if(l == 'A' && r == 'B' || (l == 'B' && r == 'A') ){
					ans += cnt % 2;
				}
			}
			l = r;
			lid = rid;
		}
	}
	for(int i = 0;i < len;++i) if(s[i] == 'C') ++ans;
	cout << ans;
	return 0;
}