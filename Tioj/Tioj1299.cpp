#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(){
	string n;
	while(cin >> n){
		int len = n.length();
		int sum = 0;
		for(int i = 0;i < len;i++){
			if(n[i] - 96 < 0) sum += n[i] - 64;
			else 	sum += n[i] - 96;
		}
		if(sum % 17 >= 0 && sum % 17 <= 2) cout << "D" << endl;
		else if(sum % 17 >= 3 && sum % 17 <= 5) cout << "C" << endl;
		else if(sum % 17 >= 6 && sum % 17 <= 9) cout << "B" << endl;
		else if(sum % 17 >= 10 && sum % 17 <= 12) cout << "A" << endl;
		else cout << "SA" << endl;
	}
	return 0;
}
