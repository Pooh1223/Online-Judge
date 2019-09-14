#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	int sure = 0,nsure = 0,cross = 0,fish = 0;
	for(int i = 0;i < s.length();++i){
		if(i != 0){
			if(fish != 0 && i - 1 == fish) continue;
			if(s[i - 1] == s[i]){
				++nsure;
			} else {
				if(i + 1 < s.length() && s[i + 1] != s[i]){
					++i;
					++sure;
					sure += nsure;
					fish = i;
					cross = 0;
				} else ++cross;
			}
		}
	}
	int cnt = s.length() - fish - 1;
	if(cnt != 0 && fish != 0 && s[fish + 1] != s[fish]){
		if(cross == 0){
			sure += cnt;
		} else {
			sure += cnt - 1;
		}
	}
	if(sure != 0) cout << sure;
	else cout << -1;
	return 0;
}