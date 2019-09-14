#include <cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	if(n == 1){
		printf("1\n");
		printf("0\n");
	} else if(n == 2){
		printf("%d\n",n - 1);
		printf("1 1\n");
	} else if(n == 3){
		printf("%d\n",n - 1);
		printf("1 0 1\n");
	} else {
		printf("%d\n",n - 1);
		for(int i = 0;i < n - 1;++i) printf("%d ",i);
		printf("%d\n",(n - 1) / 2);
	}
	return 0;
}