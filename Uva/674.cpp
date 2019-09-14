#include <bits/stdc++.h>
using namespace std;

int num[8000];
int cent[] = {1,5,10,25,50};

int main(){

	num[0] = 1;
	for(int i = 0;i < 5;++i){
		for(int j = 0;j + cent[i] <= 7489;++j){
			num[j + cent[i]] += num[j];
		}
	}

	int n;

	while(cin >> n){
		cout << num[n] << "\n";
	}

	return 0;
}