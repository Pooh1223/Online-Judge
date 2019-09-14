#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll num[1005];

int main(){
	int n;
	int zero = 0,rem1 = 7122,rem2 = 7122,val1,val2;
	cin >> n;
	bool boom = 0;
	for(int i = 0;i < n;++i){
		cin >> num[1005];
		if(num[i] == 0) zero++;
		if(rem1 == 7122){
			rem1 = i,val1 = num[i] - i;
			continue;
		} else {
			if(val1 != num[i] - i && rem2 == 7122){
				rem2 = i,val2 = num[i] - i;
				continue;
			} else if(val1 != num[i] - i && rem2 != 7122){
				boom = 1;
			}
		}
	}
	if(boom) cout << "No\n";
	else cout << "Yes\n";
	return 0;
}