#include <cstdio>
int num[1005];
int w,n;
bool search(int g){
	int cnt = 0,sum = 0;
	for(int i = 0;i < w;++i){
		if(num[i] > g) return 0;
		sum += num[i];
		if(sum > g){
			cnt++;
			sum = num[i];
		}
	}
	if(cnt > n) return 0;
	else return 1;
} 

int main(){
	while(~scanf("%d %d",&w,&n)){
		if(!w && !n) break;
		for(int i = 0;i < w;++i) scanf("%d",&num[i]);
		int l = 0,r = 100000000;
		while(r - l != 1){
			int m = (l + r) / 2;
			if(search(m)) r = m;
			else l = m;
		}
		if(search(l)) printf("%d\n",l);
		else printf("%d\n",r);
	}
	return 0;
}