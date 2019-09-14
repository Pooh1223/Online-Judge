#include <cstdio>

struct que{
	int data;
	que* next;
	que(){data = 0;next = NULL;}
};
que* front;
que* end;

void init(){front = new que(); end = front;}
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
	front -> next = front -> next -> next;
	if(front -> next == NULL) end = front;
}
int main(){
	int n;
	scanf("%d",&n);
	init();
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
