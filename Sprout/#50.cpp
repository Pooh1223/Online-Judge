#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
bool used[100005];
int ans[100005];
class tree{
public:
	tree(int _data = 0): data(_data){
		child.clear();
	}
	int data;
	vector<tree*> child;
};

void init(tree* a[],int n){
	for(int i = 0;i < n;i++){
		a[i] = new tree();
		a[i] -> data = i;
		a[i] -> child.clear();
	}
}
int dfs(tree* node,tree* root){
	int size = 1;
	for(int i = 0;i < node -> child.size();i++){
		if(root -> data == node -> data) continue;
		dfs(node -> child[i],node);
	}
	ans[node -> data] = size;
	return size;
}

int main(){
	int t,n;
	scanf("%d %d",&t,&n);
	int node,node2;
	memset(used,0,sizeof(used));
	tree* nodes[100005];
	init(nodes,n);
	used[0] = 1;
	while(t--){
		for(int i = 0;i < n - 1;i++){
			scanf("%d %d",&node,&node2);
			if(node == 0) nodes[node] -> child.push_back(nodes[node2]);
			else if(node2 == 0) nodes[node2] -> child.push_back(nodes[node]);
			else{
				if(used[node]) nodes[node] -> child.push_back(nodes[node2]);
				else nodes[node2] -> child.push_back(nodes[node]);
			}
			used[node] = 1;
			used[node2] = 1;
		}
		dfs(nodes[0],nodes[0]);
	}
	return 0;
}
