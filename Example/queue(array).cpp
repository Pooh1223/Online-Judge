#include <cstdio>
int queue[100005];
int main(){
	int n,front = -1,rear = -1;
	scanf("%d",&n);
	while(n--){
		int num;
		scanf("%d",&num);
		if(num == 1) scanf("%d",&queue[++rear]);
		else if(num == 2 && front != rear) printf("%d\n",queue[++front]);
		else printf("empty!\n");
	}
	return 0;
}
