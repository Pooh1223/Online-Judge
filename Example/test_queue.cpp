#include <iostream>
using namespace std;

int main(){
	int n = 10;
	int num[n];
	for(int i = 0;i < n;i++) num[i] = i + 1;
	cout << "Origin : ";
	for(int i = 0;i < n;i++) cout << num[i] << " ";
	cout << endl;
	num[--1];
	cout << "Pop : ";
	for(int i = 0;i < n;i++) cout << num[i] << " ";
	
	return 0;
} 
