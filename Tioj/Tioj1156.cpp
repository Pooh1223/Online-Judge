#include <iostream>
using namespace std;

int gcd(int x,int y){
	while(1){
		x %= y;
		if(x) y %= x;
		if(!x) return y;
		else if(!y) return x;
	}
}

int main(){
	int n;
	cin >> n;
	int a,b;
	if(n == 1){
		cin >> a;
		cout << a;
	}
	else if(n == 2){
		cin >> a >> b;
		cout << gcd(a,b) << endl;
	}
	else {
		for(int i = 0;i <= n;i++){
			if(i == 0) cin >> a;
			else if(i == 1) cin >> b;
			else {
				a = gcd(a,b);
				if(i == n){
					cout << a << endl;
					break;
				} 
				cin >> b;
			}
		} 
	}

	return 0;
}
