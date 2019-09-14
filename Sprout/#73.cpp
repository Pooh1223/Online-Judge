#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
int n,m;
ll num[100005];
bool search(ll x){
	ll cnt = 0,sum = 0;
	for(int i = 0;i < n;++i){
		if(num[i] > x) return 0;
		sum += num[i];
		if(sum > x){
			cnt++;
			sum = num[i];
		}
	}
	cnt++;
	if(cnt <= m) return 1;
	else return 0;	
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i = 0;i < n;++i) scanf("%lld",&num[i]);
		ll l = 0,r = 100000000;
		while(l < r){
			ll m = (l + r) / 2;
			if(search(m)) r = m;
			else l = m + 1;
		}
		printf("%lld\n",r);
		memset(num,0,sizeof(num));
	}
	return 0;
}