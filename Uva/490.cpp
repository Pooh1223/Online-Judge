#include <bits/stdc++.h>
using namespace std;

char s[103][103];
int len[103];
int jizz = -1;

int main(){
	int pos = 0;
	while(gets(s[pos])){
		len[pos] = strlen(s[pos]);
		jizz = max(jizz,len[pos]);
		pos++;
	}
	pos--;
	for(int i = 0;i < jizz;++i){
		for(int j = pos;j >= 0;--j){
			if(len[j] > i) cout << s[j][i];
			else cout << " ";
		}
		cout << "\n";
	}

	return 0;
}