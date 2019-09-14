#include <cstdio>
#include <algorithm>
using namespace std;
struct t{
	int c;
	int e;	
	/*bool operator<(const t&a){
		return e > a.e;
	}*/
}all[10005];
bool cmp(t x,t y){return x.e > y.e;}
int main(){
	int n;
	while(~scanf("%d",&n)){
		if(!n) break;
		for(int i = 0;i < n;++i){
			int a,b;
			scanf("%d %d",&all[i].c,&all[i].e);
		}
		sort(all,all + n,cmp);
		int sum = 0;
		int ans = 0;
		for(int i = 0;i < n;++i){
			sum += all[i].c;
			ans = max(sum + all[i].e,ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}