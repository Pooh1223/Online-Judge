#include <cstdio>
#include <cstring>
using namespace std;

bool line[10005][10005],pass[10005];;
int p;

void dfs(int k){
	for(int i = 1;i <= p;i++)
		if(line[k][i] && !pass[i]){
			pass[i] = 1;
			printf("%d ",i);
			dfs(i);
		}
}

int main(){
	//initialize;
	printf("Please enter the amount of the points.\n");
	scanf("%d",&p);
	printf("Now please two points to suggest the line.\nAnd enter \"0 0\" to stop this part.\n");
	int l1,l2;
	memset(line,0,sizeof(line));
	memset(pass,0,sizeof(pass));
	while(scanf("%d %d",&l1,&l2) && l1 && l2){
		line[l1][l2] = 1;
		line[l2][l1] = 1;
	}
	printf("The traversal of DFS is : ");
	//
	//DFS;
	for(int i = 1;i <= p;i++){
		if(!pass[i]){
			pass[i] = 1;
			printf("%d ",i);
			dfs(i);
		}
	}
	printf("\n");
	return 0;
}
