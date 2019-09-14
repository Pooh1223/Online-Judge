#include <iostream>
using namespace std;

int main(){
	int n,m;
	char c;
	while(cin >> n >> c >> m){
		if(!n && !m) break;
		if(c == '+') cout << n + m << endl;
		else if(c == '-') cout << n - m << endl;
		else if(c == '*') cout << n * m << endl;
		else if(c == '/'){
			int h = n / m ;
			if(h == 0) cout << h << "..." << n << endl;
			else cout << h << "..." << (n - (m * h)) << endl;
		}
	}
	
	return 0;
}
