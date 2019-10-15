#include <bits/stdc++.h>
using namespace std;

int main(){
	//how many input data
	int n,sum = 469;
	cin >> n;

	while(n--){
		int type,sec;
		double money = 0;
		cin >> type >> sec;

		if(type == 1){

			if(sec > 300) money = (sec - 300.0) * 0.05;

		} else if(type == 2){
			if(sec > 1500) money = (sec - 1500.0) * 0.1;
		} else {
			if(sec > 600) money = (sec - 600.0) * 0.1;
		}
		sum += int(money * 10.0 + 0.5) / 10.0;
	}
	cout << sum << "\n";
	return 0;
}