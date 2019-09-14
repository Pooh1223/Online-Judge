#include <bits/stdc++.h>
using namespace std;
int cnt[200003],n[200003];
queue<int> q; // which number doesn't appear in array
set<int> s,used; // 1.which number appear too many times in array
				// 2.to check if use the number
int main(){
	int t;
	cin >> t;
	for(int i = 0;i < t;++i) cin >> n[i],cnt[n[i]]++;
	int a = 0;
	for(int i = 1;i <= t;++i){
		if(cnt[i] == 0) q.push(i),a++;
		else if(cnt[i] > 1) s.insert(i);
	}
	for(int i = 0;i < t;++i){
		if(s.find(n[i]) != s.end() && !q.empty()){
			int jizz = n[i];
			if(used.find(n[i]) == used.end()){ // not use before, need to compare
				if(cnt[jizz] == 1){
					continue;
				} else if(q.front() < jizz){
					n[i] = q.front();
					q.pop();
					cnt[jizz]--;
				} else {
					used.insert(n[i]);
				}
			} else { // used before, no need to compare anymore
				n[i] = q.front();
				q.pop();
			}
		}
	}
	cout << a << "\n";
	for(int i = 0;i < t;++i) cout << n[i] << " ";
	return 0;
}