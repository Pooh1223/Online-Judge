#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,k;
int a[10005],b[10005],c[10005];
long long e[10005];
bool search(long long x){
	for(int i = 0;i < n;++i) e[i] = a[i] + b[i] * x;
	sort(e,e + n);
	int cnt = 0,j = 0;
	for(int i = 0;i < n;++i){
		while(c[i] >= e[j]){
			j++;
			if(j > n - 1) break;
		}
		if(j > n - 1) break;
		j++;
		cnt++;
		if(cnt >= k) return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i = 0;i < n;++i) scanf("%d %d",&a[i],&b[i]);
		for(int i = 0;i < n;++i) scanf("%d",&c[i]);
		sort(c,c + n);
		long long l = 0,r = 1e9;
		long long ans = r;
		if(search(ans) == 0) printf("-1\n");
		else{
			while(l <= r){
				long long m = (l + r) / 2;
				if(search(m)){
					ans = min(ans,m);
					r = m - 1;
				} 
				else l = m + 1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}