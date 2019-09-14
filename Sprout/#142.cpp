#include <iostream>
#include <cstring>
using namespace std;
int n,k,one = 0;
int num[1005],ans[1005];
inline int f(int len){
	if(len <= 0) return 0;
	if(len <= k) return ans[len] = num[len];
	if(ans[len]) return ans[len];
	else {
		int v = 0;
		for(int i = k;i < 2 * k;++i) v = max(f(len - i),v);
		return ans[len] = v + num[len];
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i = 1;i <= n;++i){
			scanf("%d",&num[i]);
			one += num[i];	
		} 
		if(k == 1) printf("%d\n",one);
		else if(k > n) printf("0\n");
		else{
			int sum = 0;
			for(int i = 0;i < k;++i) sum = max(sum,f(n - i));
			printf("%d\n",sum);
		} 
		memset(ans,0,sizeof(ans));
		one = 0;
	}
	return 0;
}