#include <cstdio>

int group[1005][1005];

int main(){
	int n;
	while(~scanf("%d",&n)){
		while(n--){
			int gid;
			scanf("%d",&gid);
			for(int i = 0;i < gid;i++){
				int num;
				scanf("%d",&num);
				group[gid][i] = num;
			}
		}
	}
	return 0;
}