#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
void gotoxy(int,int);
int way;
int dx[] = {0 , 0 , -1 , 1} , dy[] = {-1 , 1 , 0 , 0};
int main(){
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

void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
} 
