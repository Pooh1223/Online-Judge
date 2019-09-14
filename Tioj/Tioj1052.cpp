#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	getchar();
	while(n--){
		char s,c = '\n';
		int line = 0,word = 0,sum = 0,ck = 0;
		while(1){
			s = getchar();
			if(s == EOF) break;
			if(s != '\n') sum++;
			if(s == ' ' || s == '\t' || s == '\n'){
				if(c != ' ' && c != '\t' && c != '\n') word++;
			}
			if(s == '\n') line++;
			if(s == '='){
				ck++;
				if(ck == 5){
					getchar();
					sum -= 5;
					break;
				} 
			}
			else ck = 0;
			c = s;
		}
		printf("%d %d %d\n",line,word,sum);
	}
	
	return 0;
}
