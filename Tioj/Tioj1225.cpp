#include <bits/stdc++.h>
using namespace std;
#define N (int)1e6 + 3
struct t{
	int val,id;
	bool operator<(const t&a) const {
		return val > a.val;
	}
};
int l[N],r[N],num[N];
priority_queue<t> pq;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0;i < n;++i){
		cin >> num[i];
		l[i] = i - 1;
		r[i] = i + 1;
		pq.push((t){num[i],i});
	}
	long long ans = 0;
	while(pq.size() > 1){
		t top = pq.top();
		pq.pop();
		if(l[top.id] == -1){
			ans += num[r[top.id]];
			l[r[top.id]] = -1;
			continue;
		} if(r[top.id] == n){
			ans += num[l[top.id]];
			r[l[top.id]] = n;
			continue;
		}
		ans += min(num[l[top.id]],num[r[top.id]]);
		l[r[top.id]] = l[top.id];
		r[l[top.id]] = r[top.id];
	}
	cout << ans << "\n";
	return 0;
}