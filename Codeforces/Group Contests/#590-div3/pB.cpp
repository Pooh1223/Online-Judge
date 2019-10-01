#include <bits/stdc++.h>
using namespace std;

set<long long> s;
queue<long long> q;

int main(){
	int n,k;
	cin >> n >> k;

	while(n--){
		int u;
		cin >> u;
		if(!s.count(u)){
			if(q.empty()) q.push(u);
			else if(q.size() < k){
				q.push(u);
			} else if(q.size() >= k){
				s.erase(q.front());
				q.pop();
				q.push(u);
			}
			s.insert(u);
		} 
	}
	cout << q.size() << "\n";
	vector<long long> v;
	v.clear();
	while(!q.empty()){
		v.push_back(q.front());
		q.pop();
	}
	for(int i = v.size() - 1;i >= 0;--i) cout << v[i] << " ";
	return 0;
}