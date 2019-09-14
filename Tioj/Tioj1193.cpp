#include <iostream>
using namespace std;
int main(){
	long long n,m;
	while(cin >> n >> m){
		if(!n && !m) break;
		cout << n % m << "\n";
	}
	return 0;
}
