#include <bits/stdc++.h>
using namespace std;

int N[50010];
int n;
bool passed[50010];

void go(int k){
	if(!passed[k]){
		passed[k] = 1;
		go(N[k]);
	} else {
		return;
	}
}

int main(){

	cin >> n;
	for(int i = 0;i < n;++i){
		cin >> N[i];
	}
	int cnt = 0;
	for(int i = 0;i < n;++i){
		if(!passed[i]){
			go(i);
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}