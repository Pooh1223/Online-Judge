#include <bits/stdc++.h>
using namespace std;
int num[103];
vector<int> v;
int main(){
	int n;
	cin >> n;
	int cnt = 0;
	bool ck = 0;
	for(int i = 0;i < n;++i){
		int a;
		cin >> a;
		num[a]++;
		v.push_back(a);
	}
	for(int i = 0;i < 101;++i){
		if(num[i]) cnt++;
	}
	if(cnt != 2) cout << "NO\n";
	else {
		for(int i = 1;i <= 100 && !ck;++i){
			for(int j = 1;j <= 100 && !ck;++j){
				if(num[i] != 0 && num[i] == num[j] && i != j){
					cout << "YES\n" << i << " " << j << "\n";
					ck = 1;
					break;
				} 
			}
		}
		if(!ck) cout << "NO\n";
	}
	return 0;
}