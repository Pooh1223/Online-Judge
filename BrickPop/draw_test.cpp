#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;

void SetColor(int,int);

int main(){
	int a[10][10];
	for(int i = 0;i < 10;i++){
		for(int j = 0;j < 10;j++){
		a[i][j] =  j % 4 + 1;
		switch(a[i][j]){
			case 1:
				SetColor(7,4);
				cout << "  ";
			case 2:
				SetColor(7,2);
				cout << "  ";
			case 3:
				SetColor(7,6);
				cout << "  ";
			case 4:
				SetColor(7,1);
				cout << "  ";
		}
		}
		cout << endl;
	}
	
	return 0;
}

void SetColor(int f=7,int b=0){
    unsigned short ForeColor=f+16*b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
}
