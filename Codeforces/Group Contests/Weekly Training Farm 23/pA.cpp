#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int cnt = 0;
	long long a;
	while(n--){
		cin >> a;
		if(a < 0) cnt++;
	}
	cout << cnt << "\n";
	return 0;
} 
