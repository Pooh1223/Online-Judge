#include <iostream>
#include <math.h>
using namespace std;

int gcd(int a,int b){
	while(1){
		a %= b;
		if(!a) return b;
		b %= a;
		if(!b) return a;
	}
} 

int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		int num[n];
		int down = (n * (n - 1)) / 2,up = 0;
		for(int i = 0;i < n;i++) cin >> num[i];
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				if(gcd(num[i],num[j]) == 1) up++;
			}
		}
		if(!up) cout << "No estimate for this data set." << endl;
		else {
			printf("%.6f\n",(float)sqrt((6.0 * down) / up));	
		}
	}
	
	return 0;
} 
