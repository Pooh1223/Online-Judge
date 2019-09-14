#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	cout << "Lumberjacks:\n";
	while(t--){
		int v[10];
		for(int i = 0;i < 10;++i) cin >> v[i];

		bool ck = 0;

		for(int i = 1;i < 10;++i){
			if(v[i] >= v[i - 1]){
				ck = 1;
				break;
			}
		}
		if(ck){
			ck = 0;
			for(int i = 1;i < 10;++i){
				if(v[i] <= v[i - 1]){
					ck = 1;
					break;
				}
			}
		}
		if(ck) cout << "Unordered\n";
		else cout << "Ordered\n";
	}

	return 0;
}