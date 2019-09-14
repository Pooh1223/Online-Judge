#include <bits/stdc++.h>
using namespace std;
bool cmp(const int&a,const int&b){return a > b;}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n,k;
	while(cin >> n >> k){
		vector<int> v;
		while(n--){
			int j;
			cin >> j;
			v.push_back(j);
		}
		sort(v.begin(),v.end(),cmp);
		cout << v[k - 1] << "\n";
	}
	return 0;
}