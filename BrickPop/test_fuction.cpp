#include <iostream>
using namespace std;

int add(int,int);

int main(){
	
	int a,b;
	while(cin >> a >>b){
		cout << add(a,b);
	}
	return 0;
}

