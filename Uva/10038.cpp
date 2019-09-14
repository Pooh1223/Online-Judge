#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	while(cin >> t){
		long long num[3005];
		bool used[10005];
		memset(used,0,sizeof(used));

		for(int i = 0;i < t;++i){
			cin >> num[i];
			if(i){
				long long jizz = abs(num[i] - num[i - 1]);
				if(jizz < 3000) used[jizz] = 1;
			}
		} 
		bool ck = 1;
		for(int i = 1;i <= t - 1;++i){
			if(!used[i]){
				ck = 0;
				break;
			} 
		}
		if(ck) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
	return 0;
}