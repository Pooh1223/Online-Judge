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
//functions
void drawboard();
void change();
void drop();
//tools
void SetColor(int,int);
void move();
void gotoxy(int,int);
void Clr();

int way;
int dx[] = {0 , 0 , -1 , 1} , dy[] = {-1 , 1 , 0 , 0};
int a[10][10];
int ud = 0,rl = 0;
int ramx[20],ramy[20],q = 0;

int main(){
	drawboard();
	move();
	return 0;
}

void drawboard(){
	
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
	
	cout << "方向鍵移動  X鍵消除"; 
}

void change(int x,int y){
	if(a[ud][rl / 2] != 0){
		if(a[ud][rl / 2] == a[y - 1][x] && y - 1 >= 0){//up
			ramx[q] = x;
			ramy[q] = y - 1;
			q++;
			change(x,y - 1);
		}
		if(a[ud][rl / 2] == a[y][x + 1] && x + 1 <= 9){//right
			ramx[q] = x + 1;
			ramy[q] = y;
			q++;
			change(x + 1,y);
		}
		if(a[ud][rl / 2] == a[y + 1][x] && y + 1 <= 9){//down
			ramx[q] = x;
			ramy[q] = y + 1;
			q++;
			change(x,y + 1);
		}
		if(a[ud][rl / 2] == a[y][x - 1] && x - 1 >= 0){//left
			ramx[q] = x - 1;
			ramy[q] = y;
			q++;
			change(x - 1,y);
		}
	}
}
void redraw(){
	Clr();
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
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
			else if (a[i][j] == 0){
				SetColor(7,0);
				cout<<"  ";
			}
		}
	  cout << endl;
	}
	cout << "方向鍵移動  X鍵消除"; 
	
}

void drop(){
	int temp[10];
	for(int i = 9;i >= 0;i--){
		for(int h = 0;h < 10;h++){
			if(a[i][h] == 0){
		    	for(int j=0;j<10;j++){
		    		temp[i]=0;
		    	}
				for(int k = i - 1;k >= 0;k--){
					temp[k+1]=a[k][h];	
				}
				for(int n = i ;n >= 0;n--){
					a[n][h]=temp[n];
				}
			}
		}
	}
	for(int j=0;j<=8;j++){
		for(int i=j;i<=8;i++){
			if((a[0][i]==0)&&(a[1][i]==0)&&(a[2][i]==0)&&(a[3][i]==0)&&(a[4][i]==0)&&(a[5][i]==0)&&(a[6][i]==0)&&(a[7][i]==0)&&(a[8][i]==0)&&(a[9][i]==0)){
				for(int k=0;k<10;k++){
					a[k][i]=a[k][i+1];
					a[k][i+1]=0;
				}
	    	}
		}
    }
}
 
void SetColor(int f=7,int b=0){
    unsigned short ForeColor=f+16*b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
}

void move(){ 
	gotoxy(0,0);
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
                    ud--;
                    break;
                case 80 ://down
                    way = 1;
                    ud++;
                    break;
                case 75 ://left
                    way = 2;
                    rl--;
                    break;
                case 77 ://right
                    way = 3;
                    rl++;
                    break;
            }
            
        point.F += dx[way];
        point.S += dy[way];
        gotoxy(point.F , point.S);
        }
        if(ch==120){//按x
           	change((rl / 2),ud);
        	a[ud][rl / 2] = 0;
        	for(int i = 0;i < q;i++){
        		a[ramy[i]][ramx[i]] = 0;
			}
           	redraw();
          	Sleep(500);
        	drop();
        	redraw();
		}
    }
}

void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

void Clr()
{
        COORD coordScreen = { 0, 0 }; 
        DWORD cCharsWritten; 
        CONSOLE_SCREEN_BUFFER_INFO csbi; 
        DWORD dwConSize; 
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        GetConsoleScreenBufferInfo(hConsole, &csbi); 
        dwConSize = csbi.dwSize.X * csbi.dwSize.Y; 
        FillConsoleOutputCharacter(hConsole, TEXT(' '),
                dwConSize, 
                coordScreen,
                &cCharsWritten); 
        GetConsoleScreenBufferInfo(hConsole, &csbi); 
        FillConsoleOutputAttribute(hConsole,
                csbi.wAttributes,
                dwConSize,
                coordScreen,
                &cCharsWritten); 
        SetConsoleCursorPosition(hConsole, coordScreen);

}
