#include <bits/stdc++.h>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> > pq;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		pq.push(a);
	}
	long long jizz = 0;
	while(pq.size() != 1){
		long long p = pq.top(); pq.pop();
		long long q = pq.top(); pq.pop();
		jizz += p + q;
		pq.push(p + q);
	}
	cout << jizz << "\n";
	return 0;
}