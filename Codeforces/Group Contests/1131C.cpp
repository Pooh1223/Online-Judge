#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0;i < n;++i){
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(),v.end());
	int st = 0,ed = n - 1;
	int num[103];
	for(int i = 0;i < n;++i){
		if(!(i % 2)){
			num[st] = v[i];
			st++;
		} else {
			num[ed] = v[i];
			ed--;
		}
	}
	for(int i = 0;i < n;++i) cout << num[i] << " ";

	cout << "\n";

	return 0;
}