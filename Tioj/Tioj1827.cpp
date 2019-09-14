#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int len,ask;
	scanf("%d %d",&len,&ask);
	int sparse[20][len + 1];
	for(int i = 0;i < len;i++) scanf("%d",&sparse[0][i]);
	for(int i = 1;(1 << i) <= len;i++)
		for(int j = 0;j + (1 << i) <= len;j++)
			sparse[i][j] = min(sparse[i - 1][j],sparse[i - 1][j + (1 << (i - 1))]);
			
	while(ask--){
		int l,r;
		scanf("%d %d",&l,&r);
		l += 1;
		r += 1;
		int p = 31 - __builtin_clz(abs(r - l) + 1);
		printf("%d\n",min(sparse[p][l - 1],sparse[p][r - (1 << p)])); 
	}	
	return 0;
}
