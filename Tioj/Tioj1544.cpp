#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		string num1,num2;
		cin >> num1 >> num2;
		int len1 = num1.length(),len2 = num2.length();
		if(len1 > len2) cout << 0 << endl;
		else if(len1 < len2) cout << 1 << endl;
		else {
			for(int j = 0;j < len2;j++){
				if(num1[j] > num2[j]){
					cout << 0 << endl;
					break;
				} 
				else if(num1[j] < num2[j]){
					cout << 1 << endl;
					break;
				} 
			}
		} 
	}
	return 0;
} 
