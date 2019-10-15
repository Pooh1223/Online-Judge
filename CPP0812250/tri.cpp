#include <iostream>
using namespace std;

int main(){
	int k,cnt = 1;
	cin >> k;
	for(int i = 1;i <= k;++i){
		for(int j = 1;j <= i;++j){
			if(i <= 4) cout << cnt++ << "  ";
			else cout << cnt++ << " ";
		}
		cout << "\n";
	}
	return 0;
}