#include <iostream>
using namespace std;

int main(){
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n){
		if(!n) break;
		int a[n],max = 0;
		long long sum = 1;
		for(int i = 0;i < n;i++){
			cin >> a[i];
			if(max < a[i]) max = a[i];
			sum += a[i];
		}
		sum += max;
		cout << sum << "\n";
	}
	return 0;
} 
