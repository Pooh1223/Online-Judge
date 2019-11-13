#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(cin >> s){
		if(s == "0") break;
		int nm = 0,cnt = 0;
		cout << s;

		do{
			for(int i = 0;i < s.length();++i) nm += s[i] - '0';
			if(!(nm % 9) && nm != 9){
				cnt++;
				s = to_string(nm);
			} else break;
			nm = 0;
		}while(1);

		if(nm == 9) cnt++;
		if(!cnt){
			cout << " is not a multiple of 9.\n";
		} else {
			cout << " is a multiple of 9 and has 9-degree " << cnt << ".\n";
		}
	}
	return 0;
}