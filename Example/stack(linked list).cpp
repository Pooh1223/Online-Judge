#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* build(){return NULL;}

Node* push(Node* top,int num){
	Node* newnode;
	newnode = (Node*) malloc(sizeof(Node));
	newnode -> data = num;
	newnode -> next = top;
	top = newnode;
	return top;
}

Node* pop(Node* top){
	cout << top -> data << "\n";
	Node* nnode;
	nnode = top;
	if(nnode == NULL) return NULL;
	top = top -> next;
	free(nnode);
	return top;
}

int main(){
	Node* first;
	first = build();
	int n,cnt = 0;
	cin >> n;
	while(n--){
		int ck,num;
		cin >> ck;
		if(ck == 1){
			cnt++;
			cin >> num;
			first = push(first,num);
		} 
		else if(cnt > 0 && ck == 2){
			cnt--;
			first = pop(first);
		} 
		else cout << "empty!\n";
	}
	return 0;
}
