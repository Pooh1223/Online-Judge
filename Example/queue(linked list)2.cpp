#include <cstdio>

struct que{
	int data;
	que* next;
	que(){data = 0;next = NULL;}
};
que* front;
que* end;

void push(int n){
	que* back = new que();
	back -> data = n;
	end -> next = back;
	end = back;
}

void pop(){
	if(front == end){
		printf("empty!\n");
		return;
	}
	printf("%d\n",front -> next -> data);
	front = front -> next;
	if(front -> next == NULL) end = front;
}

int main(){
	front = new que();
	end = front;
	int n;
	scanf("%d",&n);
	while(n--){
		int ck;
		scanf("%d",&ck);
		if(ck == 1){
			int num;
			scanf("%d",&num);
			push(num);
		}
		else pop();
	} 
	
	return 0;
}
