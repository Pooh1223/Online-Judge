#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int m = 2e9 + 887;
vector<int> ans;
struct tree{
	int data;
	tree* left;
	tree* right;
	tree(){data = 2e9 + 7;left = NULL;right = NULL;}
};
tree* root = new tree();
void push(tree* node,int n){
	if(n < node -> data){
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

void query(tree* node,int n){
	int jizz = abs(n - node -> data);
	if(node -> left == NULL && node -> right == NULL){
		if(m > jizz) m = jizz;
	} 
	if(node -> data > n){
		if(node -> left == NULL){
			if(m > jizz) m = jizz;
		}
		else{
			if(m > jizz) m = jizz;
			query(node -> left,n);
		} 
	}
	else if(node -> data < n){
		if(node -> right == NULL){
			if(m > jizz) m = jizz;
		}
		else{
			if(m > jizz) m = jizz;
			query(node -> right,n);
		} 
	}
	else{
		m = 0;
	}
	if(m >= jizz){
		ans.push_back(node -> data);
		m = jizz;
	}
}

int main(){
	int n;
	string order;
	cin >> n;
	int cnt = 0;
	while(n--){
		cin >> order;
		int num;
		cin >> num;
		if(order[0] == 'i'){
			if(cnt == 0) root -> data = num;
			else push(root,num);
			cnt++;
		}
		else if(order[0] == 'd'){
			kill(root,num);
			cnt--;
		}
		else {
			query(root,num);
			sort(ans.begin(),ans.end());
			for(int i = 0;i < ans.size();i++){
				if(i == 0) cout << ans[i];
				else cout << " " << ans[i]; 
			}
			cout << "\n";
			ans.clear();
			m = 2e9 + 7;
		}
	}
	return 0;
}