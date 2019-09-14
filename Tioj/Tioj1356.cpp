#include <cstdio>
int cnt = 1;
inline void honai(int n,int a,int b,int c){
	if(n == 1) {
		printf("#%d : move the dish from #%d to #%d \n",cnt,a,b);
		cnt++;
		printf("#%d : move the dish from #%d to #%d \n",cnt,b,c);
		cnt++;
	}
	else {
		honai(n - 1,a,b,c);
		printf("#%d : move the dish from #%d to #%d \n",cnt,a,b);
		cnt++;
		honai(n - 1,c,b,a);
		printf("#%d : move the dish from #%d to #%d \n",cnt,b,c);
		cnt++;
		honai(n - 1,a,b,c);
	}
}
int main(){
	int a = 1,b = 2,c = 3;
	int n;
	scanf("%d",&n);
	honai(n,a,b,c);
	return 0;
}
