#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		priority_queue<long long,vector<long long>,greater<long long> > pq;
		for(int i = 0;i < n;++i){
			int k;
			cin >> k;
			pq.push(k);
		}
		long long sum = 0;
		while(--n){
			int x = pq.top();
			pq.pop();
			int y = pq.top();
			pq.pop();
			sum += x + y;
			pq.push(x + y);
		}
		cout << sum << "\n";
	}
	return 0;
}