#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> map[40005];
int color[40005],n,m,l1,l2;
bool pass[40005],jizz;

void dfs(int k){
	for(int i = 0;i < map[k].size() && jizz;i++){
		if(!pass[map[k][i]]){
			pass[map[k][i]] = 1;
			if(color[k] == 1) color[map[k][i]] = 2;
			else color[map[k][i]] = 1;
			dfs(map[k][i]);
		}
		else {
			if(color[k] == color[map[k][i]]){
				jizz = 0;
				printf("No\n");
				break;
			}
		}
	}
}

int main(){
	while(~scanf("%d %d",&n,&m)){
		if(!n && !m) break;
		for(int i = 0;i <= n;i++) map[i].clear();
		memset(color,0,sizeof(color));
		memset(pass,0,sizeof(pass));
		while(m--){
			scanf("%d %d",&l1,&l2);
			map[l1].push_back(l2);
			map[l2].push_back(l1);
		}
		jizz = 1;
		color[1] = 1;
		dfs(1);
		if(jizz) printf("Yes\n");
	}
	return 0;
}
