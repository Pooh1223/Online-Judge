#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100003
using namespace std;
inline int lowbit(int x){return x & (-x);}
int a[N],b[N];
int n;
void add(int x){
	while(x <= n){
		b[x]++;
		x += lowbit(x);
	}
}
int sum(int x){
	int sum = 0;
	while(x > 0){
		sum += b[x];
		x -= lowbit(x);
	}
	return sum;
}
int main(){
	int cnt = 1;
	while(~scanf("%d",&n)){
		if(!n) break;
		for(int i = 0;i < n;++i) scanf("%d",&a[i]),b[i] = a[i];
		sort(b,b + n);
		for(int i = 0;i < n;++i) a[i] = lower_bound(b,b + n,a[i]) - b + 1;
		memset(b,0,sizeof(b));
		long long ans = 0;
		for(int i = 0;i < n;++i){
			ans += (long long)(i - sum(a[i]));
			add(a[i]);
		}
		printf("Case #%d: %lld\n",cnt,ans);
		cnt++;
	}
	return 0;
}