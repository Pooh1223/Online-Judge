#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){

		vector<int> v;
		queue<int> q;
		priority_queue<int> pq;

		bool isstack = 1,isqueue = 1,ispq = 1;

		while(n--){
			int t,nm;
			cin >> t >> nm;

			if(t == 1){

				if(isstack) v.push_back(nm);
				if(isqueue) q.push(nm);
				if(ispq) pq.push(nm);

			} else {
				if(!v.empty() && v.back() != nm){
					v.pop_back();
					isstack = 0;
				} else if(v.empty()) isstack = 0;
				else v.pop_back();

				if(!q.empty() && q.front() != nm){
					q.pop();
					isqueue = 0;
				} else if(q.empty()) isqueue = 0;
				else q.pop();

				if(!pq.empty() && pq.top() != nm){
					pq.pop();
					ispq = 0;
				} else if(pq.empty()) ispq = 0;
				else pq.pop();

			}
		}
		int cnt = (int)ispq + (int)isqueue + (int)isstack;
		if(cnt > 1) cout << "not sure\n";
		else if(cnt == 1){
			if(isstack) cout << "stack\n";
			else if(ispq) cout << "priority queue\n";
			else cout << "queue\n";
		} else {
			cout << "impossible\n";
		}
	}
	return 0;
}