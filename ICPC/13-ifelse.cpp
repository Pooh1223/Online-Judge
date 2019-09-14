#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
ll num[100005];
bool cmp(int a,int b){return a > b;}
int main(){
	ll n,k,sum = 0;
	scanf("%lld %lld",&n,&k);
	for(int i = 1;i <= n;++i){
		scanf("%lld",&num[i]);
		sum += num[i];
	} 
	sort(num + 1,num + n + 1,cmp);
	ll ans = 0;
	for(int i = 1;i <= n;++i){
		ans += i * num[i];
	}
	ans += (k - sum) * n;
	printf("%lld\n",ans);
	return 0;
}