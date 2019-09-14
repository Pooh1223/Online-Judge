#include <bits/stdc++.h>
using namespace std;
int t[10];
int main(){
	int k;
	string s,a;
	cin >> k >> s;
	a = s;
	int sum = 0;
	for(int i = 0;i < s.size();++i){
		sum += s[i] - '0';
		t[s[i] - '0']++;
	}
	if(sum >= k) cout << 0 << "\n";
	else {
		int cnt = 0;
		sum = k - sum;
		for(int i = 0;i <= 9 && sum > 0;++i){
			while(t[i] && sum > 0){
				t[i]--;
				sum -= 9 - i;
				cnt++;
			}
		}
		cout << cnt;
	}
	return 0;
}