#include <bits/stdc++.h>
using namespace std;

int main(){
	bool over = 0;
	string str,out;
	int s,t;
	cin >> s >> t;
	cin >> str;
	cout << str;

	for(int i = 1;i < s && !over;++i){
		string ss = str;
		for(int j = 0;i + j < s && !over;++j){
			if(ss[j] == str[i + j] && (i + j + 1) == s){
				over = 1;
				for(int k = j + 1;k < s;++k){
					out += ss[k];
				}
			} else if(ss[j] != str[i + j]){
				break;
			}
		}
	}
	
	while(--t){
		if(out != "") cout << out;
		else cout << str;
	}
	cout << "\n";

	return 0;
}