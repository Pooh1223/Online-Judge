#include <cstdio>
int stack[100005];
int main(){
	int n,top = -1;
	scanf("%d",&n);
	while(n--){
		int num;
		scanf("%d",&num);
		if(num == 1) scanf("%d",&stack[++top]);
		else if(num == 2 && top != -1) printf("%d\n",stack[top--]);
		else printf("empty!\n");
	}
	return 0;
} 
