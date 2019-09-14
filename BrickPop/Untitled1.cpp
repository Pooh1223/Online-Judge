#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
#include <string>
#include <conio.h>

#define pii pair<int,int>
#define F first
#define S second

using namespace std;

void SetColor(int,int);
void move();
void gotoxy(int,int);


int way;
int dx[] = {0 , 0 , -1 , 1} , dy[] = {-1 , 1 , 0 , 0};

int main(){
	int a[10][10];
	srand(time(NULL));
	for(int i = 0;i < 10;i++){
		for(int j = 0;j < 10;j++){
			a[i][j] = rand() % 4 + 1;
			if (a[i][j] == 1){
				SetColor(7,4);
				cout << "  ";
				SetColor(7,0);
			}
			else if (a[i][j] == 2){
				SetColor(7,2);
				cout << "  ";
				SetColor(7,0);
			}
			else if (a[i][j] == 3){
				SetColor(7,6);
				cout << "  ";
				SetColor(7,0);
			}
			else if (a[i][j] == 4){
				SetColor(7,1);
				cout << "  ";
				SetColor(7,0);
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

void move(){
    int ch , ch2;
    pii point;
    point.F = 0;
    point.S = 0;
    while(1){
        ch = getch();
        if(ch == 224){
            ch2 = getch();
            switch(ch2){
                case 72 :
                    way = 0;
                    break;
                case 80 :
                    way = 1;
                    break;
                case 75 :
                    way = 2;
                    break;
                case 77 :
                    way = 3;
                    break;
            }
        }
        point.F += dx[way];
        point.S += dy[way];
        gotoxy(point.F , point.S);
    }
}
