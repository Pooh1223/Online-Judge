#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
	cin.tie(0);
	int n;
	while(1){
		cin >> n;
		if(!n) break;
		priority_queue<long long,vector<long long>,greater<long long> > q;
		for(int i = 0;i < n;i++){
			int t;
			cin >> t;
			q.push(t);
		}
		long long sum = 0;
		for(int i = 0;i < n - 1;i++){
			long long tmp1 = q.top(); q.pop();
			long long tmp2 = q.top(); q.pop();
			sum += tmp1 + tmp2;
			q.push(tmp1 + tmp2);
		}
		printf("%lld\n",sum);
	}
	return 0;