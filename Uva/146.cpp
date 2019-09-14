#include <bits/stdc++.h>
using namespace std;

int main(){

	char str[60];
	while(~scanf("%s",str)){
		if(str[0] == '#') break;
		int len = strlen(str);
		if(next_permutation(str,str + len)){
			printf("%s\n",str);
		} else printf("No Successor\n");
	}

	return 0;
}