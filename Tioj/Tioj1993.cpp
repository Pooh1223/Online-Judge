#include <bits/stdc++.h>
#include <bitset>
using namespace std;
bitset<100003> bit;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		bit.reset();
		bit[0] = 1;
		while(n--){
			int a,b,c;
			cin >> a >> b >> c;
			bit = (bit << a) | (bit << b) | (bit << c);
		}
		int jizz = 0;
		for(int i = k;i > 0;--i){
			if(bit[i]){
				jizz = i;
				break;
			} 
		}
		if(jizz != 0) cout << jizz << "\n";
		else cout << "no solution\n";
	}
	return 0;
}