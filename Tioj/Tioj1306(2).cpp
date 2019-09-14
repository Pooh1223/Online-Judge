#include <bits/stdc++.h>
#define ll long long
#define M (long long)2147483647
#define P (long long)89
using namespace std;
string s1,s2;
ll hs[10005],x[10005];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	x[0] = 1;
	for(int i = 1;i < 10005;++i) 
		x[i] = (x[i - 1] * P) % M;

	int t;
	cin >> t;
	while(t--){
		cin >> s1;
		hs[0] = 0;
		for(int i = 1;i <= (int)s1.size();++i)
			hs[i] = (hs[i - 1] * P + s1[i - 1] - 'a') % M;
		int n;
		cin >> n;
		while(n--){
			cin >> s2;
			int u = 0,ans = 0;
			for(int i = 0;i < (int)s2.size();++i)
				u = (u * P + s2[i] - 'a') % M;
			for(int i = 0;i + (int)s2.size() <= (int)s1.size();++i){
				ll jizz = (hs[i + (int)s2.size()] - hs[i] * x[(int)s2.size()]) % M;
				if(jizz < 0) jizz += M;
				if(jizz == u) ans++;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}