#include <bits/stdc++.h>
using namespace std;

int num[100005];
long long n,k,a,b;

long long search(long long l,long long r){
	long long ans = 0;
	int len = upper_bound(num + 1,num + k + 1,r) - lower_bound(num + 1,num + k + 1,l);

	if(!len){
		return ans = a;
	} else {
		ans = len * b * (r - l + 1);
	}

	if(r - l < 1) return ans;

	ans = min(ans,search(l,(l + r) / 2) + search((l + r) / 2 + 1,r));

	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k >> a >> b;

	for(int i = 1;i <= k;++i) cin >> num[i];
	sort(num + 1,num + k + 1);

	long long p = 1;
	while(n--) p *= 2;

	cout << search(1,p);

	return 0;
}