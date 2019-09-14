#include <iostream>
using namespace std;

int xx(int);

int main(){
	int a;
	while(cin >> a){
		cout << xx(a) << endl;
	}
	
	return 0;
}

int xx(int i){
	if (i == 1) return 1;
	else {
		i--;
		return i + xx(i);
	}
}
