#include <bits/stdc++.h>
using namespace std;

struct s{
	double cp;
	int id;

	bool operator<(const s& a)const{
		if(cp == a.cp) return id < a.id;
		return cp > a.cp;
	}
}nm[1003];

int main(){

	int t;
	cin >> t;
	for(int k = 0;k < t;++k){
		if(k) cout << "\n";
		int n;
		cin >> n;

		for(int i = 0;i < n;++i){
			double a,b;
			cin >> a >> b;

			nm[i].cp = b / a;
			nm[i].id = i + 1;
		}
		sort(nm,nm + n);
		for(int i = 0;i < n;++i){
			if(!i) cout << nm[i].id;
			else cout << " " << nm[i].id;
		}
		cout << "\n";
	}
	return 0;
}