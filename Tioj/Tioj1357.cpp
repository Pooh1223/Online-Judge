#include <cstdio>
int dp[51];
int main(){
	int n;
	scanf("%d",&n);
	dp[1] = 1;
	for(int i = 2,j = 2,before = 1,k = 2;i < 51;i++){
		dp[i] = dp[i - 1] + j;
		if(i - before == k){
			before = i;
			k++;
			j *= 2;
		}
	}
	while(n--){
		int a;
		scanf("%d",&a);
		printf("%d\n",dp[a]);
	}
	return 0;
}
