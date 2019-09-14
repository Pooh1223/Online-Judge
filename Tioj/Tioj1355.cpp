#include <cstdio>
int cnt = 1;
void honai(int n,char a,char b,char c){
	if(n == 1) {
		printf("#%d : move the dish from #%c to #%c \n",cnt,a,c);
		cnt++;
	}
	else {
		honai(n - 1,a,c,b);
		honai(1,a,b,c);
		honai(n - 1,b,a,c);
	}
}
int main(){
	char a = '1',b = '2',c = '3';
	int n;
	scanf("%d",&n);
	honai(n,a,b,c);
	return 0;
}
