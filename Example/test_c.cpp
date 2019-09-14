#include <iostream>
using namespace std;

int main(){
	long long i,j,num,sum = 0;
	while(cin >> num){
		for(i = 2;i <= num;i++){
			for(j = 2;j <= i;j++){
				if(i % j == 0) break;
			}
			if(i == j) sum++;
		}
		cout << sum << endl;
		sum = 0;
	}
	return 0;
}
