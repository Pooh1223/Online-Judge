#include <cstdio>
#include <cstring>

int main(){
	int n,m;
	while(~scanf("%d %d",&m,&n)){
		if(!m && !n) break;
		int t,w,g,error[m + 1],right[m + 1];
		int time = 0,solve = 0;
		memset(error,0,sizeof(error));
		memset(right,0,sizeof(right));
		while(n--){
			scanf("%d %d %d",&t,&w,&g);
			if(g && !right[w]){
				time += (error[w] * 20 + t);
				solve++;
				right[w]++;	
			}
			else error[w]++;
		}
		printf("%d %d\n",time,solve);
	}
	
	return 0;
}
