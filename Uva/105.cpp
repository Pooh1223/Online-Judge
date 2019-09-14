#include <bits/stdc++.h>
using namespace std;

int num[10003];

int main(){

	int l,h,r;
	while(cin >> l >> h >> r){
		for(int i = l;i < r;++i){
			num[i] = max(num[i],h);
		}
	}

	int nh = 0;
	bool st = 0;
	for(int i = 0;i <= 10000;++i){
		if(nh != num[i]){
			if(!st){
				st = 1;
				cout << i << " " << num[i];
			} else cout << " " << i << " " << num[i];
		} 
		nh = num[i];
	}
	cout << "\n";
	return 0;
}