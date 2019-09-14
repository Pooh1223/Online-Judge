#include <cstdio>
#include <cstdlib>

struct que{
	int data;
	que* next;
};

que* front = NULL; 
que* rear = NULL;

void push(int n){
	que* back;
	back = (que*) malloc (sizeof(que));
	back -> data = n;
	back -> next = NULL;
	if(rear == NULL) front = rear = back;
	else{
		rear -> next = back;
		rear = back;
	}
}
int pop(){
	que* begin;
	begin = front;
	if(begin == NULL){
		printf("empty!\n");
		front = rear = NULL;
	} 
	else{
		printf("%d\n",front -> data);
		front = front -> next;
	}
	free(begin);
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
