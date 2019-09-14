#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		bool relate[n + 1][n + 1];
		memset(relate,0,sizeof(relate));
		while(m--){
			int num1,num2;
			scanf("%d %d",&num1,&num2);
			relate[num1][num2] = 1;
			relate[num2][num1] = 1;
		}
		int k;
		scanf("%d",&k);
		for(int i = 1;i <= k;i++){
			if(relate[i][k]){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
} 
