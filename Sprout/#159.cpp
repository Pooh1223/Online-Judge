#include <bits/stdc++.h>
using namespace std;
int v[105];
bool can[20005];
int main(){
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(can,0,sizeof(can));
		memset(v,0,sizeof(v));
		can[0] = 1;
		int n,m;
		cin >> n >> m;
		int cnt = 0;
		for(int i = 0;i < n;++i){
			int c,k;
			cin >> c >> k;
			int sum = 0,last = 0;
			for(int j = 1;sum < k;j <<= 1){
				last = sum;
				sum += j;
				if(sum > k) break;
				else{
					v[cnt] = j * c;
					cnt++;
				}
			}
			if(sum > k) v[cnt++] = (k - last) * c;
		}
		for(int i = 0;i < cnt;++i){
			for(int j = m;j - v[i] >= 0;--j){
				can[j] = can[j] || can[j - v[i]];
			}
		}
		if(can[m]) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}