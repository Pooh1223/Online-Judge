#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stringstream ss;
	string a,b;
	int aa,bb;
	cin >> a >> b;
	ss << a;
	ss >> aa;
	ss.clear();
	ss.str("");
	ss << b;
	ss >> bb;
	if(aa > bb) cout << a << "\n";
	else if(aa < bb) cout << b << "\n";
	else{
		for(int i = 0;;i++){
			if(a[i] > b[i]){
				cout << a << "\n";
				break;
			}
			else if(a[i] < b[i]){
				cout << b << "\n";
				break;
			}
		}
	}
}
