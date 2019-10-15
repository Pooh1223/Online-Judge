#include <iostream>
using namespace std;

int n[100003][2];

int main(){
	int k;
	cin >> k;


	for(int i = 1;i <= k;++i){
		for(int j = k - i;j >= 0;--j) cout << "  ";

		if(i == 1){
			cout << "1";
		} else if(i == 2){
			n[0][0] = 1;
			n[1][0] = 1;
			cout << "1   1";
		} else {
			for(int j = 0;j < i;++j) n[j][1] = n[j][0];
			for(int j = 1;j <= i;++j){
				if(j == 1 || j == i){
					cout << "1   ";
					if(j != 1) n[j - 1][0] = 1;

					continue;
				}
				cout << (n[j - 1][0] = n[j - 2][1] + n[j - 1][1]) << "   ";
			}
			
		}
		cout << "\n";
	}
	return 0;
}