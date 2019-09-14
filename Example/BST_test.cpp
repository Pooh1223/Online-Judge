#include <cstdio>

struct tree{
	int data;
	tree* left;
	tree* right;
	tree(){data = 0;left = NULL;right = NULL;}
};
tree* head = new tree();
void push(tree* node,int n){
	if(node -> data > n){
		if(node -> left == NULL){
			tree* back = new tree();
			back -> data = n;
			node -> left = back;
		}
		else push(node -> left,n);
	}
	else{
		if(node -> right == NULL){
			tree* back = new tree();
			back -> data = n;
			node -> right = back;
		}
		else push(node -> right,n);
	}
}

tree* findmin(tree* node){
	if(node -> left != NULL){
		findmin(node -> left);
	}
	else return node;
}

tree* kill(tree* node,int n){
	if(node == NULL) return node;
	else if(node -> data > n) node -> left = kill(node -> left,n);
	else if(node -> data < n) node -> right = kill(node -> right,n);
	else{
		if(node -> left == NULL && node -> right == NULL){
			delete node;
			node = NULL;
		}
		else if(node -> left == NULL){
			tree* back = node;
			node = node -> right;
			delete back;
		}
		else if(node -> right == NULL){
			tree* back = node;
			node = node -> left;
			delete back;
		}
		else{
			tree* back = findmin(node -> right);
			node -> data = back -> data;
			node -> right = kill(node -> right,back -> data);
		}
	} 
	return node;
}

void print(tree* node){
	if(node -> left != NULL) print(node -> left);
	if(node -> right != NULL) print(node -> right);
	printf("%d\n",node -> data);
}

int main(){
	int n;
	scanf("%d",&n);
	int id,num;
	for(int i = 0;i < n;i++){
		scanf("%d %d",&id,&num);
		if(i == 0) head -> data = num;
		else if(id == 1) push(head,num);
		else if(id == 2) kill(head,num);
		print(head);
	}
	return 0;
}
