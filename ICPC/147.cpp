#include <bits/stdc++.h>
using namespace std;
int choco[800005],cnt = 0;
int main(){
	int n,k;
	cin >> n >> k;
	while(n--){
		int a,b;
		cin >> a >> b;
		choco[a + b]++;
	}
	for(int i = 1;i < 800005;++i){
		if(choco[i] == k) cnt++;
	}
	cout << cnt << "\n";
	return 0;
}