#include <bits/stdc++.h>
using namespace std;

bool used[23];
int nm[23];

int main(){
	int n,m,c,t = 1;
	while(cin >> n >> m >> c){
		if(!n && !m && !c) break;
		
		memset(used,0,sizeof(used));

		bool boom = 0;
		int cnt = 0,mx = -1;

		for(int i = 1;i <= n;++i) cin >> nm[i];

		for(int i = 0;i < m;++i){
			int id;
			cin >> id;

			if(boom == 1) continue;

			if(!used[id]){
				used[id] = 1;
				cnt += nm[id];
				if(cnt > c){
					boom = 1;
				}
				mx = max(mx,cnt);
			} else {
				used[id] = 0;
				cnt -= nm[id];
			}
		}

		cout << "Sequence " << t++ << "\n";

		if(boom){
			cout << "Fuse was blown.\n\n";
		} else {
			cout << "Fuse was not blown.\n";
			cout << "Maximal power consumption was " << mx << " amperes.\n\n";
		}
	}
	return 0;
}