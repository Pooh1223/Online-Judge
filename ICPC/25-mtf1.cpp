#include <iostream>
#include <string>
using namespace std;
string s;
int main(){
	cin >> s;
	bool yee = 0;
	for(int i = 0;i < s.length();++i){
		if(i + 2 < s.length() && s[i] == 'M' && s[i + 1] == 'T' && s[i + 2] == 'F') i += 2;
		else s[i] = '.';
	}
	cout << s ;
	return 0;
}