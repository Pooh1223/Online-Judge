#include <cstdio>
using namespace std;

int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	long long sum[n],j;
	sum[0] = 0;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&j);
		sum[i] = sum[i - 1] ^ j;
	}
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%lld\n",sum[l - 1] ^ sum[r]);
	}
	return 0;
}
