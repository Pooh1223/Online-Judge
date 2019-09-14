#include <cstdio>

int main(){
	int b,n;
	while(~scanf("%d%d",&b,&n)){
		if(n == 1){
			for(int i = 1;b--;i += 2){
				for(int j = 1;j <= i;++j) printf("*");
				printf("\n");
			}
		} else {
			for(int i = 1;b--;i += 2){
				for(int j = 1;j <= i;++j){
					if(b == 0){
						printf("*");
					} else {
						if(j == 1 || j == i) printf("*");
						else printf(" ");
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}