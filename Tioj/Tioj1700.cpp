#include <cstdio>
int main(){
	int n;
	while(~scanf("%d",&n)){
		int a,b;
		scanf("%d",&a);
		if(n == 1) printf("%d\n",a);
		else {
			n -= 1;
			while(n--){
				scanf("%d",&b);
				int c;
				if(a < b){
					c = a;
					a = b;
					b = c;
				} 
				while(b){
					a %= b;
					c = a;
					a = b;
					b = c;
				}
			}
			printf("%d\n",a);
		}
	}
	return 0;
}
