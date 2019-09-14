#include <cstdio>

int main(){
	int n;
	while(~scanf("%d",&n)){
		int ans = 0;
		for(int i = 3;i <= n;i *= 3){
			ans += (n / i);
		}
		printf("%d\n",ans); 
	}
	return 0;
}