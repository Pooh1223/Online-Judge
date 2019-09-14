#include <cstdio>

struct node{
	int data;
	node* next;
	node(){data = 0;next = NULL;}
};
node* car[100005];
int pre[100005];
void init(){
	for(int i = 0;i < 100005;i++){
		car[i] = new node();
		car[i] -> data = i;
		if(i){
			car[i - 1] -> next = car[i];
			pre[i] = i - 1;
		} 
	}
}
void pop(int n){
	car[pre[n]] -> next = car[n] -> next;
	pre[car[n] -> next -> data] = car[pre[n]] -> data;
}
void over(int n){
	if(pre[n] != 0){
		car[pre[pre[n]]] -> next = car[n];
		car[pre[n]] -> next = car[n] -> next;
		car[n] -> next = car[pre[n]];
		pre[n] = pre[pre[n]];
		pre[car[n] -> next -> next -> data] = car[n] -> next -> data;
		pre[car[n] -> next -> data] = n;
	}
}
void print(int n){
	node* temp = car[0] -> next;
	for(int i = 0;i < n;i++){
		if(i == 0) printf("%d",temp -> data);
		else printf(" %d",temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}
int main(){
	init();
	int n,m;
	scanf("%d %d",&n,&m);
	while(m--){
		int id,num;
		scanf("%d %d",&id,&num);
		if(id == 0){
			pop(num);
			n--;
		} 
		else over(num);
	}
	print(n);
	return 0;
}