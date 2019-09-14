#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int t,n;
vector<int> tree[100005];
int ans[100005];
void init(){for(int i = 0;i < 100005;i++) tree[i].clear();}
int dfs(int node,int root){
	int size = 1;
	for(int i = 0;i < tree[node].size();i++){
		if(tree[node][i] == root) continue;
		size += dfs(tree[node][i],node);
	}
	ans[node] = size;
	return size;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		init();
		memset(ans,0,sizeof(ans));
		for(int i = 0;i < n - 1;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		ans[0] = dfs(0,0);
		for(int i = 0;i < n;i++) printf("node %d: %d\n",i,ans[i]);
	}	
	return 0;
}
