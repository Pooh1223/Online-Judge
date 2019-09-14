#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,cnt = 1;

	while(cin >> n >> m){
		if(!n && !m) break;
		cout << "CASE# " << cnt++ << ":\n";
		int num[10003];
		for(int i = 1;i <= n;++i) cin >> num[i];
		sort(num + 1,num + 1 + n);
		
		for(int i = 0;i < m;++i){
			int q,l = 1,r = n;
			cin >> q;
			while(l <= r){
				int m = (l + r) / 2;
				if(num[m] < q) l = m + 1;
				else r = m - 1;
			}
			if(num[l] == q) cout << q << " found at " << l << "\n";
			else cout << q << " not found\n";
		}
	}

	return 0;
}