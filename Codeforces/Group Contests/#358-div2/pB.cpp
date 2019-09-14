#include <bits/stdc++.h>
using namespace std;
int num[100005];
int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;++i) cin >> num[i];
	sort(num,num + n);
	int cnt = 1;
	for(int i = 0;i < n;++i){
		if(i == 0) num[i] = cnt;
		if(cnt != num[i + 1]) cnt++;
	}
	cout << cnt << "\n";
	return 0;
}