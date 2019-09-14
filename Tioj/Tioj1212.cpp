#include <cstdio>
#define jizz 100000
int d[505][505];

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		if(!n && !m) break;
		for(int i = 0;i <= n;i++)
			for(int j = 0;j <= n;j++)
				d[i][j] = jizz;
		while(m--){
			int p1,p2;
			scanf("%d %d",&p1,&p2);
			d[p1][p2] = 1;
		}		
		int mn = jizz;
		for(int k = 1;k <= n;k++)
			for(int i = 1;i <= n;i++)
				for(int j = 1;j <= n;j++)
					if (d[i][k] + d[k][j] < d[i][j])
						d[i][j] = d[i][k] + d[k][j];
		for(int i = 1;i <= n;i++) if(d[i][i] < mn) mn = d[i][i];
		if(mn == jizz) printf("0\n");
		else printf("%d\n",mn);
	}
	return 0;
}
