#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		int n,m;
		cin >> n >> m;
		int h[103];
		for(int i = 0;i < m;++i) cin >> h[i];
		int sum = 0;
		for(int i = 1;i <= n;++i){
			if(!(i % 7) || i % 7 == 6) continue;
			for(int j = 0;j < m;++j){
				if(!(i % h[j])){
					sum++;
					break;
				}
			}
		}
		cout << sum << "\n";
	}

	return 0;
}
