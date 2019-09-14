#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		int mx = 0,mn = 15;
		float sum = 0;
		for(int i = 0,j;i < n;i++){
			cin >> j;
			if(mx < j) mx = j;
			if(mn > j) mn = j;
			sum += j;
		}
		sum -= (mx + mn);
		printf("%.2f\n",(sum / (n - 2)) + 1e-9);
	}
	return 0;
}
