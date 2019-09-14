#include <cstdio>

int main(){
	int a,b;
	scanf("%lld %lld",&a,&b);
	int ans = 0;
	while(a != b){
		if(a > b) a >>= 1;
		else b >>= 1;
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}