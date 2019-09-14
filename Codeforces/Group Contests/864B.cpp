#include <bits/stdc++.h>
using namespace std;
bitset<30> used;
int main(){
	int n;
	cin >> n;
	int mx = -1;
	for(int i = 0;i <= n;++i){
		char c = getchar();
		if(c >= 'a' && c <= 'z'){
			used[c - 'a'] = 1;
		} else {
			int cnt = 0;
			for(int j = 0;j < used.size();++j){
				if(used[j]){
					//cout << j << "\n";
					cnt++;
				}
			}
			mx = max(mx,cnt);
			used.reset(); 
		}
	}
	int cnt = 0;
	for(int j = 0;j < used.size();++j){
		if(used[j]){
			//cout << j << "\n";
			cnt++;
		}
	}
	mx = max(mx,cnt);
	cout << mx << "\n";
	return 0;
}