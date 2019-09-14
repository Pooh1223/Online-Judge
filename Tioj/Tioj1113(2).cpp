#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char solve[8];
bool used[8];
char s[8];

void back(int n,int len,char a[]){
	if(n == len){
		for(int i = 0;i < len;i++) cout << solve[i];
		cout << "\n"; 
		return;
	}
	for(int i = 0;i < len;i++){
		if(!used[i]){
			used[i] = 1;
			solve[n] = a[i];
			back(n + 1,len,a);
			used[i] = 0;
		}
	}
}

int main(){
	while(scanf("%s",s) != EOF){
		memset(used,0,sizeof(used));
		int len = strlen(s);
		sort(s,s + len);
		back(0,len,s);
		cout << "\n";
	}
	
	return 0;
}
