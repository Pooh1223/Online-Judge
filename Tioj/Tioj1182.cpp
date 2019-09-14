#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int people,score;
		cin >> people;
		if(!people) break;
		cin >> score;
		int num,min = -100000000,max = 100000000;
		for(int i = 0;i < (people - 1);i++){
			cin >> num;
			if(num > score && num < max) max = num;
			if(num < score && num > min) min = num;
		}
		cout << max << " " << min << endl;
	}
	
	return 0;
}
