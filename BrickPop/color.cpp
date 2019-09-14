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
	srand(time(NULL));
	for(int i = 0;i < 10;i++){
		int j = rand() % 4 + 1;
		switch(j){
			case 1:
				SetColor(7,4);
				cout << j;
				SetColor(7,0);
			case 2:
				SetColor(7,2);
				cout << j;
				SetColor(7,0);
			case 3:
				SetColor(7,6);
				cout << j;
				SetColor(7,0);
			case 4:
				SetColor(7,1);
				cout << j;
				SetColor(7,0);
		}
		cout << " " << i << " ";
	}	
	
	return 0;
}

void SetColor(int f=7,int b=0){
    unsigned short ForeColor=f+16*b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
}
