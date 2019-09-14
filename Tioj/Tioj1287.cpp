#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		int num[n];
		for(int i = 0;i < n;i++) cin >> num[i];
		sort(num,num + n);
		for(int i = 0;i < n;i++){
			cout << num[i] << " ";
			if(i == n - 1) cout << endl;
		} 
	}
	return 0;
}
