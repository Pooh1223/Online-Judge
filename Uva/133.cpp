#include <bits/stdc++.h>
using namespace std;

bool alive[23];

int main(){
	int n,m,k;
	while(~scanf("%d %d %d",&n,&k,&m)){
		if(!n && !k && !m) break;
		fill(alive,alive + n,1);

		int remain = n;

		int posk = 0,posm = n - 1;

		while(remain){
			int kk = k;
			int mm = m;

			int cnt = 0;

			while(cnt != kk){
				if(alive[posk]) cnt++;
				if(cnt != kk) posk = (posk + n + 1) % n;
			}
			
			cnt = 0;

			while(cnt != mm){
				if(alive[posm]) cnt++;
				if(cnt != mm) posm = (posm + n - 1) % n;
			}

			alive[posk] = 0;
			alive[posm] = 0;

			if(remain == n){
				if(posk == posm) printf("%3d",posk + 1);
				else printf("%3d%3d",posk + 1,posm + 1);
			} else {
				if(posk == posm) printf(",%3d",posk + 1);
				else printf(",%3d%3d",posk + 1,posm + 1);
			}

			if(posk == posm) remain -= 1;
			else remain -= 2;

		}

		cout << "\n";
	}
	return 0;
}