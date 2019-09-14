#include <bits/stdc++.h>
using namespace std;
int p[1000006];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	//cout << n << "\n";
	for(int i = 0;i < n;++i) cin >> p[i];
	long long st = n - 1,lt = n - 1 - p[n - 1],sum = 0;
	if(lt < 0) return cout << 1 << "\n",0;
	for(int i = n - 2;i >= 0;--i){
		if(i < lt){
			sum += st - lt;
			st = i;
		}
		lt = i - p[i] < lt ? i - p[i] : lt;
		if(lt < 0){lt = 0; break;}
	}
	sum += st - lt;
	cout << n - sum << "\n";
	return 0;
}