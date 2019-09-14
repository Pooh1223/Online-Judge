#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	cin >> n;
	int sum = 0;
	while(n--){
		string car;
		cin >> car;
		int len = car.length();
		if(car[2] == car[3] && car[4] == car[5]) {
			if(car[2] == car[5]){
				//cout << "It's 4" << endl;
				sum += 2000;
			}
			else {
				//cout << "It's 2" << endl; 
				sum += 1500;
			}
		}
		else if((car[2] == car[3] && car[3] == car[4]) || (car[3] == car[4] && car[4] == car[5])){
			//cout << "It's 3" << endl; 
			sum += 1000;
		} 
	}
	cout << sum << endl;	
	return 0;
} 
