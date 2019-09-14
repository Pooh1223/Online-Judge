#include <bits/stdc++.h>
using namespace std;
vector<int> v[100003];
int main(){
	int n,k,m,pos;
	bool p = 0;
	cin >> n >> k >> m;
	for(int i = 0;i < n;++i){
		int q;
		cin >> q;
		v[q % m].push_back(q);
		if((int)v[q % m].size() == k) p = 1,pos = q % m;
	}
	if(!p) cout << "No\n";
	else {
		cout << "Yes\n";
		for(int i = 0;i < k;++i){
			cout << v[pos][i] << " ";
		}
	}
	return 0;
}