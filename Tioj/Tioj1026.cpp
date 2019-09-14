#include <iostream>
using namespace std;

int main(){
	int step;
	while(cin >> step){
		if(step == 0) continue;
		int total = 1,cnt = 1;
		for(;total * 2 < step;total *= 2,cnt++);
		char order[cnt];
		int sum = 0;
		cout << cnt << endl;
		for(int i = cnt - 1;total >= 1;total /= 2,i--){
			if(step - sum > 0){
				order[i] = '+';
				sum += total;
			} 
			else{
				order[i] = '-';
				sum -= total;
			} 
		}
		for(int j = 0;j < cnt;j++) cout << order[j];
	}
	return 0;
}
