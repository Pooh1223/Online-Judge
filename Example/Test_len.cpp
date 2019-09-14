#include <iostream>
using namespace std;

int main(){
	char a[1000];
	char b[1000];
	for(int i = 0;i < 2;i++) a[i] = 1;
	for(int i = 0;i < 5;i++) b[i] = 1;
	cout << a.length() << endl;
	cout << b.length() << endl;
	
	return 0;
}
