#include <iostream>
#include <vector>
#define ll long long
using namespace std;
vector<ll> v[3];
ll a(ll num,ll n){
	if(n == 0) return 1;
	if(n == 1) return num;
	if(n % 2 == 0) return a(num,n / 2) * a(num,n / 2);
	else return a(num,n / 2) * a(num,n / 2) * num;
}
ll ans(ll n,ll m){
	if(n < 0) n = 0;
	if(n % 3 == 2 && m % 3 == 2) return 0;
	v[0].clear();
	v[1].clear();
	v[2].clear();
	if(n % 3 == 0){
		while(n >= 3){
			v[0].push_back(n % 3);
			n /= 3;
		}
		v[0].push_back(n);
	} else if(n % 3 == 1){
		ll n2 = n - 1;
		while(n >= 3){
			v[0].push_back(n % 3);
			n /= 3;
		}
		v[0].push_back(n);
		while(n2 >= 3){
			v[2].push_back(n2 % 3);
			n2 /= 3;
		}
		v[2].push_back(n2);
		for(int i = 0;i < v[0].size();++i){
			v[0][i] += v[2][i];
			if(v[0][i] >= 3) v[0][i] -= 3;
		}
	} else {
		int cnt = 1;
		while(n > a(3,cnt)){
			//printf("%d\n",a(3,cnt));
			cnt++;
		} 
		//printf("cnt : %d\n",cnt);
		for(int i = 0;i <= cnt;++i) v[0].push_back(0);
	}
	/*while(!v[0].empty()){
		printf("%d",v[0].back());
		v[0].pop_back();
	}
	printf("\n");*/
	v[2].clear();
	if(m % 3 == 0){
		while(m >= 3){
			v[1].push_back(m % 3);
			m /= 3;
		}
		v[1].push_back(m);
	} else if(m % 3 == 1){
		ll m2 = m - 1;
		while(m >= 3){
			v[1].push_back(m % 3);
			m /= 3;
		}
		v[1].push_back(m);
		while(m2 >= 3){
			v[2].push_back(m2 % 3);
			m2 /= 3;
		}
		v[2].push_back(m2);
		for(int i = 0;i < v[1].size();++i){
			v[1][i] += v[2][i];
			if(v[1][i] >= 3) v[1][i] -= 3;
		}
	} else {
		int cnt = 1;
		while(m > a(3,cnt)){
			//printf("%d\n",a(3,cnt));
			cnt++;
		} 
		//printf("cnt : %d\n",cnt);
		for(int i = 0;i <= cnt;++i) v[1].push_back(0);
	}
	/*while(!v[1].empty()){
			printf("%d",v[1].back());
			v[1].pop_back();
	}*/
	v[2].clear();
	for(int i = 0;i < min(v[0].size(),v[1].size());++i){
		int u = v[1][i] - v[0][i];
		if(u < 0) u += 3;
		v[2].push_back(u);
	}
	for(int i = v[0].size();i < v[1].size();++i){
		if(v[1][i] >= 0 && v[1][i] < 3) v[2].push_back(v[1][i]);
	}
	ll sum = 0;
	for(int i = 0;i < v[2].size();++i){
		sum += v[2][i] * a(3,i);
	}
	return sum;
}
int main(){
	ll x,y;
	scanf("%lld%lld",&x,&y);
	//ans(x - 1,y);
	printf("%lld",ans(x - 1,y));
	return 0;
}