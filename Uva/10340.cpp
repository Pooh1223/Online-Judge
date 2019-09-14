#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	
	while(cin >> s >> t){
		int iter = 0;
		for(int i = 0;i < t.length();++i){
			if(t[i] == s[iter]){
				iter++;
			}
		}
		
		if(iter == s.length()) cout << "Yes\n";
		else cout << "No\n";
	}
	
	return 0;
}