#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	while(cin >> a >> b){
		cout << "[";
		if(a == 1){
			cout << "0;" << b << "]\n";
			continue;
		} else if(b == 1){
			cout << a << ";0]\n";
			continue; 
		}
		for(int i = 0;;++i){
			if(i && i != 1) cout << ",";

			if(a > b){
				if(!i){
					cout << a / b << ";";
					a = a - (a / b) * b;
				} else {
					cout << a / b;
					a = a - (a / b) * b;
				}
			} else {
				if(!i){
					cout << "0;";
					swap(a,b);
				} else {
					cout << b / a;
					b = b - (b / a) * a;
				}
			}
			if(!a || !b) break;
		}
		cout << "]\n";
	}
	return 0;
}