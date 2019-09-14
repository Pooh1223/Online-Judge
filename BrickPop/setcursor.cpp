#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
void set_mouse_pos(int,int);
void move();
void gotoxy(int,int);

int way;
int dx[] = {0 , 0 , -1 , 1} , dy[] = {-1 , 1 , 0 , 0};

int main(){
	for(int i = 0;i < 10;i++){
		for(int j = 0;j < 10;j++){
			cout << 87 << " ";
		}
		cout << endl;
	}
	set_mouse_pos(0,0);
	move();
	return 0;
}

void set_mouse_pos(int a,int b){
  POINT cursor;
  GetCursorPos(&cursor);

  cursor.x = a;
  cursor.y = b;
  SetCursorPos(cursor.x,cursor.y);
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
                case 72 ://up
                    way = 0;
                   // ud++;
                    break;
                case 80 ://down
                    way = 1;
                    
                    break;
                case 75 ://left
                    way = 2;
                    break;
                case 77 ://right
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
