#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll w1,w2,h1,h2,sum = 0;
	cin >> w1 >> h1 >> w2 >> h2;
	sum += (h1 * 2 + w1 + 2) + (h2 * 2 + w2 + 2) + (w1 - w2);
	cout << sum << "\n";
	
	return 0;
}