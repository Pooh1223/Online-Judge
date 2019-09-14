#include <bits/stdc++.h>
using namespace std;
int m[370];
int f[370];
int main(){
	cin.tie(0);
	//ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0;i < n;++i){
		char g;
		int a,b;
		cin >> g >> a >> b;
		if(g == 'M'){
			for(int j = a;j <= b;++j){
				m[j]++;
				//cout << j << " : " << m[j] << "\n";
			} 
				//cout << "jizz1\n";
		} else {
			for(int j = a;j <= b;++j){
				f[j]++;
				//cout << j << " : " << f[j] << "\n";
			} 
				//cout << "jizz2\n";
		}
	}
	int ans = 0;
	for(int i = 1;i <= 366;++i){
		ans = max(ans,min(m[i],f[i]));
		//if(m[i] && f[i]) cout << "jizz!\n";
	} 
	cout << 2 * ans << "\n";
	return 0;
}