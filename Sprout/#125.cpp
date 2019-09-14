#include <cstdio>
using namespace std;
#define ll long long
const ll jizz = 10000019;
ll num[1000005],a[1000005];
int n;
ll merge(ll l,ll r){
	if(r - l == 1) return 0;
	ll m = (l + r) / 2;
	ll sum = merge(l,m) % jizz;
	sum += merge(m,r) % jizz;
	sum %= jizz;
	int left = l,right = m,k = l;
	ll cnt = 0;
	for(left = l;left < m;++left){
		while(right < r && num[right] < num[left]){
			cnt += num[right] % jizz;
			right++;
		}
		sum += cnt % jizz;
		sum += ((right - m) * num[left]) % jizz;
		sum %= jizz;
	}
	left = l,right = m;
	while(left < m || right < r){
		if(left < m && (right >= r || num[left] < num[right])) a[k++] = num[left++];
		else a[k++] = num[right++];
	}
	for(int i = l;i < r;++i) num[i] = a[i];
	return sum % jizz;
}
int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;++i) scanf("%lld",&num[i]);
	printf("%lld\n",merge(0,n) % jizz);
	return 0;
}