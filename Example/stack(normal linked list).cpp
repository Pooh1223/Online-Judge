#include <cstdio>
#include <cstdlib>

struct que{
	int data;
	que* front;
};
que* top = NULL;

void push(int n){
	que* back;
	back = (que*) malloc (sizeof(que));
	back -> data = n;
	back -> front = top;
	top = back;
}

void pop(){
	que* back;
	back = top;
	if(back != NULL){
		printf("%d\n",back -> data);
		top = top -> front;
	} 
	else printf("empty!\n");
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int ck,num;
		scanf("%d",&ck);
		if(ck == 1){
			scanf("%d",&num);
			push(num);
		}
		else pop();
	}
	return 0;
}
