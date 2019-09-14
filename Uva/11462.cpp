#include <bits/stdc++.h>
using namespace std;

int p[2000003];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n){
		if(!n) break;
		for(int i = 0;i < n;++i) cin >> p[i];
		sort(p,p + n);
		for(int i = 0;i < n;++i){
			if(i) cout << " ";
			cout << p[i];
		} 
		cout << "\n";
	}
	return 0;
}