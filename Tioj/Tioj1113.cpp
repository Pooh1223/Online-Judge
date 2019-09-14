#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	char s[8];
	while(scanf("%s",s) != EOF){
		int len = strlen(s);
		sort(s,s + len);
		do {
			puts(s); 
		} while(next_permutation(s,s + len));
		cout << "\n";
	}
	return 0;
}
