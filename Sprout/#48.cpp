#include <cstdio>

struct tree{
	int data;
	tree* left;
	tree* right;
	tree(){data = 0;left = NULL;right = NULL;}
};
tree* head = new tree();
void push(int n,tree* node){
	if(node -> data > n){
		if(node -> left == NULL){
			tree* back = new tree();
			back -> data = n;
			node -> left = back;
		}
		else push(n,node -> left);
	}
	else{
		if(node -> right == NULL){
			tree* back = new tree();
			back -> data = n;
			node -> right = back;
		}
		else push(n,node -> right);
	}
}

void print(tree* node){
	if(node -> left != NULL) print(node -> left);
	if(node -> right != NULL) print(node -> right);
	printf("%d\n",node -> data);
}

int main(){
	int n;
	scanf("%d",&n);
	head -> data = n;
	while(~scanf("%d",&n)){
		push(n,head);
	}
	print(head);
	return 0;
}
