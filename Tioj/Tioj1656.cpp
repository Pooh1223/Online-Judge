#include <cstdio>

int main(){
	int y;
	while(~scanf("%d",&y)){
		if(!(y % 3) && (y % 9) || !(y % 27)) printf("sad\n");
		else printf("happy\n");
	}
	return 0;
}
