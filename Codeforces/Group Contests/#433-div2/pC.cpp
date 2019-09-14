#include <bits/stdc++.h>
using namespace std;
struct t{
	int val,id;
	bool operator<(const t&a)const{
		return val < a.val;
	}
};
int num[300005];
int q[300005];
int main(){
	cin.tie(0);
	priority_queue<t> pq;
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;++i) cin >> num[i];
	long long ans = 0;
	if(k + 1 >= n){
		for(int i = 1;i <= n;++i) pq.push((t){num[i],i});
		for(int i = 1;!pq.empty();++i){
			int rate = pq.top().val;
			int id = pq.top().id;
			ans += (long long)(i + k - id) * (long long)rate;
			q[id] = i + k;
			pq.pop();
		}
	} else {
		for(int i = 1;i <= k + 1;++i) pq.push((t){num[i],i});
		for(int i = 1,j = k + 2;!pq.empty();++i,++j){
			int rate = pq.top().val;
			int id = pq.top().id;
			ans += (long long)(i + k - id) * (long long)rate;
			q[id] = i + k;
			pq.pop();
			if(j <= n) pq.push((t){num[j],j});
		}
	}
	cout << ans << "\n";
	for(int i = 1;i <= n;++i) cout << q[i] << " ";
	cout << "\n";

	return 0;
}