#include <bits/stdc++.h>
using namespace std;

int r[20];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for(int i = 0;i < n;++i) cin >> r[i];
	for(int i = 0;i < pow(2,(double)n);++i){ //0 -> - , 1 -> +
		int jizz = i,sum = 0;
		for(int j = 0;j < n;++j){
			if(jizz & 1){
				sum += r[j];
			} else {
				sum -= r[j];
			}
			jizz >>= 1;
		}
		if(!(sum % 360)){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}