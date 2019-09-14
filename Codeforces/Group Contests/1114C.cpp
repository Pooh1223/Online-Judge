#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll,int> mp;
vector<ll> v;

void calb(ll num){
	ll root = sqrt(num) + 1;
	int p = 0;
	for(int i = 2;i <= root;){
		if(!(num % i)){
			mp[i]++;
			num /= i;
			if(!p){
				v.push_back(i);
				++p;
			} else if(v[p - 1] != i){
				v.push_back(i);
				++p;
			}
		} else {
			++i;
		}
	}
	if(num != 1){
		mp[num]++;
		v.push_back(num);
	} 
}

ll caln(ll num){
	ll ans = 1e18;
	map<ll,int>::iterator iter;
	for(int i = 0;i < v.size();++i){
		ll now = num,sum = 0;
		while(now){
			sum += now / v[i];
			now /= v[i];
		}
		iter = mp.find(v[i]);
		ans = min(sum / iter -> second ,ans);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll n,b;
	cin >> n >> b;

	calb(b);
	cout << caln(n) << "\n";

	return 0;
}