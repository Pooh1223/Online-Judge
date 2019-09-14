#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int num;
		cin >> num;
		if((num % 10) % 2) cout << 1 << endl;
		else cout << 0 << endl;
	}
	
	return 0;
} 
