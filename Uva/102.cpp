#include <bits/stdc++.h>
using namespace std;

long long comb[6];
//BCG,BGC,CBG,CGB,GBC,GCB

int main(){
	long long num[10];
	while(cin >> num[0]){
		long long sum = num[0];
		for(int i = 1;i < 9;++i){
			cin >> num[i];
			sum += num[i];
		} 

		comb[0] = num[0] + num[5] + num[7];
		comb[1] = num[0] + num[4] + num[8];
		comb[2] = num[2] + num[3] + num[7];
		comb[3] = num[2] + num[4] + num[6];
		comb[4] = num[1] + num[3] + num[8];
		comb[5] = num[1] + num[5] + num[6];

		long long mx = -1;
		int id = -1;

		for(int i = 0;i < 6;++i){
			if(mx < comb[i]){
				mx = comb[i];
				id = i;
			}
		}

		long long ans = sum - mx;

		switch(id){
			case 0:
				cout << "BCG " << ans << "\n";
				break;
			case 1:
				cout << "BGC " << ans << "\n";
				break;
			case 2:
				cout << "CBG " << ans << "\n";
				break;
			case 3:
				cout << "CGB " << ans << "\n";
				break;
			case 4:
				cout << "GBC " << ans << "\n";
				break;
			case 5:
				cout << "GCB " << ans << "\n";
				break;
		}
	}

	return 0;
}