#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	int a[10],b[10];
	for(int i = 0;i <= 9;i++)
		cin >> a[i];
	for(int i = 0;i <= 9;i++)
		b[i] = a[i];	
	sort(b,b+10);
	for(int i = 0;i <= 9;i++)
		cout << b[i] <<" ";
	return 0;
}
