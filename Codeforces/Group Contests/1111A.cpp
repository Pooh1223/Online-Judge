#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;

	if(s1.size() != s2.size()){
		cout << "NO\n";
		return 0;
	}

	int len = min(s1.size(),s2.size());

	for(int i = 0;i < len;++i){
		if(isVowel(s1[i]) ^ isVowel(s2[i])){
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	return 0;
}