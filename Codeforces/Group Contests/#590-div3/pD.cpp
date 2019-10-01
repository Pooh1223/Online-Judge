#include <bits/stdc++.h>
using namespace std;

bool used[30];

int main(){
	string s;
	int q;

	cin >> s >> q;

	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int p;
			char c;
			cin >> p >> c;
			s[p - 1] = c;
		} else {
			memset(used,0,sizeof(used));
			int l,r;
			cin >> l >> r;
			l--;
			r--;
			int cnt = 0;
			for(int i = l;i <= r;++i){
				if(!used[s[i] - 'a']){
					used[s[i] - 'a'] = 1;
					cnt++;
				}
			}
			cout << cnt << "\n";
		}
	}

	return 0;
}