#include <bits/stdc++.h>
using namespace std;
bool first[30];
int lastPos[30],cnt[30];
int main(){
	string s;
	cin >> s;
	//cout << "jizz\n";
	for(int i = 0;i < s.size();++i){
		int c = s[i] - 'a'; 
		//cout << c << "\n";
		if(!first[c]){
			first[c] = 1;
			lastPos[c] = i;
			cnt[c] = i + 1;
		} else {
			cnt[c] = max(cnt[c],i - lastPos[c]);
			lastPos[c] = i;
		}
	}
	int ans = 1e9;
	for(int i = 0;i < 26;++i){
		cnt[i] = max(cnt[i],(int)s.size() - lastPos[i]);
		if(first[i]) ans = min(cnt[i],ans);
	}
	if(ans == 1e9){
		cout << s.size() / 2 + 1 << "\n";
	} 
	else cout << ans << "\n";
	return 0;
}