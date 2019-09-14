#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> gragh[100005];
bool used[100005];
struct tree{
	int mx;
	int sum;
};
tree node[100005];
int dfs(int n){
	for(int i = 0;i < gragh[n].size();i++){
		if(!used[gragh[n][i]]){
			used[gragh[n][i]] = 1;
			int t = dfs(gragh[n][i]);
			node[n].sum += t;
			node[n].mx = max(node[n].mx,t);
		}
	}
	return node[n].sum + 1;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i = 0;i < n;i++){
			node[i].mx = 0;
			node[i].sum = 0;
			used[i] = 0;
			gragh[i].clear();
		}
		for(int i = 0;i < n - 1;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			gragh[a].push_back(b);
			gragh[b].push_back(a);
		}
		used[0] = 1;
		dfs(0);
		int ans = n,id;
		for(int i = 0;i < n;i++){
			int t = max(node[i].mx,n - node[i].sum - 1);
			if(ans > t){
				ans = t;
				id = i;
			}
		}
		printf("%d\n",id);
	}
	return 0;
}