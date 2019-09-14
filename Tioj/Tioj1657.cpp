#include <cstdio>
using namespace std;

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= m;++j){
				if(j == 1) printf("%d*%d=%d",i,j,i * j);
				else printf(" %d*%d=%d",i,j,i * j);
			}
			printf("\n");
		}
	}
	return 0;
}