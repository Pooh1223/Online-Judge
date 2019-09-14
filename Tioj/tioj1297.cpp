#include <iostream>
using namespace std;

int main(){
	int a;
	while(cin >> a){
		if(a < 0){
			cout << "stupid" << endl;
			continue;
		}
		if(a == 0){
			cout << 0 << endl;
			continue;
		} 
		int b = (int)(((double) a) * 100 / 101) - 2;
		for(;b < 1026;b++){
			if(a == (int)(((double) b) * 101 / 100))break;
		}
		if(b < 0 || b > 1024) cout << "stupid" << endl;
		else cout << b << endl; 
	}
	return 0;
}
