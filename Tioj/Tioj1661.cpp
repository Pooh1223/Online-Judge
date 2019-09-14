#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		int q,num[103];
		for(int i = 0;i < n;i++) cin >> num[i];
		cin >> q;
		while(q--){
			int ix1,ix2;
			cin >> ix1 >> ix2;
			swap(num[ix1],num[ix2]);
		}
		for(int i = 0;i < n;i++){
			cout << num[i];
			if(i != n - 1) cout << " ";
			else cout << "\n";
		}
	}
	return 0;
}
