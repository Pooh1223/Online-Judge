#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <conio.h>
#define pii pair<int,int>
#define F first
#define S second
#define enter 13

using namespace std;
//functions
void drawboard();
int change(int,int,int);
void drop();
void check();
void startmenu();
void endgame();
//tools
void SetColor(int,int);
void move();
void gotoxy(int,int);
void Clr();
//ints
int way;
int dx[] = {0 , 0 , -1 , 1} , dy[] = {-1 , 1 , 0 , 0};
int a[1000][1000];
int ud = 0,rl = 0;
int score = 0;
int sum = 0;
int ram;
int size = 10;
int colornums = 4; 

int main(){
	startmenu();
	return 0;
}

void startmenu(){
	int ch;
	gotoxy(0,0);
	rl=0;ud=0;sum=0;
	memset(a,0,sizeof(a));
	cout <<"╔═══════════════════════════╗        "<<endl;
	cout <<"║___.         .__        __                            ║        "<<endl;
	cout <<"║\\\_ |_________|__| ____ |  | __ ______   ____ ______   ║      "<<endl;
	cout <<"║ | __ \\_  __ \\  |/ ___\\|  |/ / \\____ \\ /  _ \\\\____ \\  ║"<<endl;
	cout <<"║ | \\_\\ \\  | \\/  \\  \\___|    <  |  |_> >  <_> )  |_> > ║  "<<endl;
	cout <<"║ |___  /__|  |__|\\___  >__|_ \\ |   __/ \\____/|   __/  ║     "<<endl;
	cout <<"║     \\/              \\/     \\/ |__|          |__|     ║     "<<endl;
	cout <<"╚═══════════════════════════╝        "<<endl;
	cout <<"請輸入大小?(Best : 10)(Max: 15)";
	cin >> size;
	cout <<"顏色數量?(Best : 3)(Max : 14)"; 
	cin >> colornums;
	if(colornums>=15){
		cout <<"不要無視規則!"<<endl;
		system("pause");
		Clr();
		startmenu();
	}   
	gotoxy(22 , 12);
	cout << "Press ENTER!";
	gotoxy(2 , 15);
	cout << "方向鍵移動  Z鍵提前結束 X鍵消除 (消除0視為結束遊戲) " << endl;
	while(1){
		ch = getch();
		if(ch == 13){
			Clr();
			drawboard();
			move();
		}
	} 
}

void drawboard(){
	srand(time(NULL));
	for(int i = 0;i < size;i++){
		for(int j = 0;j <= size;j++){
			a[i][j] = rand() % colornums + 1;
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
			}else if(a[i][j] == 5){
				SetColor(7,3);
				cout << "  ";
				SetColor(7,0);
			}else if(a[i][j] == 6){
				SetColor(7,5);
				cout << "  ";
				SetColor(7,0);
			}else if(a[i][j] == 7){
				SetColor(7,8);
				cout << "  ";
				SetColor(7,0);
			}else if(a[i][j] == 8){
				SetColor(7,7);
				cout << "  ";
				SetColor(7,0);
			}else if(a[i][j] == 9){
				SetColor(7,9);
				cout << "  ";
				SetColor(7,0);
			}else if(a[i][j] == 10){
				SetColor(7,10);
				cout << "  ";
				SetColor(7,0);
			}else if(a[i][j] == 11){
				SetColor(7,11);
				cout << "  ";
				SetColor(7,0);
			}else if(a[i][j] == 12){
				SetColor(7,12);
				cout << "  ";
				SetColor(7,0);
			}
			else if(a[i][j] == 13){
				SetColor(7,13);
				cout << "  ";
				SetColor(7,0);
			}else if(a[i][j] == 14){
				SetColor(7,14);
				cout << "  ";
				SetColor(7,0);
			}			
	  }
	  cout << "︳" << endl;
	}
	for(int i = 0;i <= size;i++){
		cout << "￣" ;
		if(i == size) cout << endl;
	}
	cout << "方向鍵移動  X鍵消除  Z鍵提前結束" << endl;
	cout << "Score : 0" << endl; 
}

int change(int x,int y,int g){
	if(a[y][x] == g){
		a[y][x] = 0;
		int qq = 1;
		if(y != 0   )qq += change(x,y - 1,g);
    	if(x != size)qq += change(x + 1,y,g);
    	if(y != size)qq += change(x,y + 1,g);
    	if(x != 0   )qq += change(x - 1,y,g);
    	return qq;
	} 
	return 0;
}
void redraw(){
	Clr();
	for(int i = 0;i < size;i++){
		for(int j = 0;j <= size;j++){
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
			else if(a[i][j] == 5){
				SetColor(7,3);
				cout << "  ";
				SetColor(7,0);
			}
			else if(a[i][j] == 6){
				SetColor(7,5);
				cout << "  ";
				SetColor(7,0);
			}
			else if(a[i][j] == 7){
				SetColor(7,8);
				cout << "  ";
				SetColor(7,0);
			}
			else if(a[i][j] == 8){
				SetColor(7,7);
				cout << "  ";
				SetColor(7,0);
			}
			else if(a[i][j] == 9){
				SetColor(7,9);
				cout << "  ";
				SetColor(7,0);
			}
			else if(a[i][j] == 10){
				SetColor(7,10);
				cout << "  ";
				SetColor(7,0);
			}
			else if(a[i][j] == 11){
				SetColor(7,11);
				cout << "  ";
				SetColor(7,0);
			}else if(a[i][j] == 12){
				SetColor(7,12);
				cout << "  ";
				SetColor(7,0);
			}
			else if(a[i][j] == 13){
				SetColor(7,13);
				cout << "  ";
				SetColor(7,0);
			}
			else if(a[i][j] == 14){
				SetColor(7,14);
				cout << "  ";
				SetColor(7,0);
			}
		}
		cout << "︳" << endl;
	}
	for(int i = 0;i <= size;i++){
		cout << "￣" ;
		if(i == size) cout << endl;
	}
	cout << "方向鍵移動  X鍵消除  Z鍵重新開始" << endl;
	cout << "Score : "<< sum << endl; 
	if(score == 0){
		cout << "Cannot delete only one cube!" << endl;
	}
}

void drop(){
	bool ya=0;
	int temp[size];
	for(int i = 0;i < size;i++){
		for(int j = 0;j <= size;j++){
			if(a[i][j] == 0){
		    	memset(temp , 0 , sizeof(temp));
				for(int k = i - 1;k >= 0;k--){
					temp[k + 1] = a[k][j];	
				}
				for(int n = i ;n >= 0;n--){
					a[n][j] = temp[n];
				}
			}
		}
	}
	for(int j = 0;j <= size - 1; j++){
		for(int i = size - 1;i >= 0;i--){
			for(int k = 0;k < size; k++){
				if(a[k][i] != 0){
					ya = 1;
				}
			}
			if(ya==0){
				for(int k = 0;k < size;k++){
					a[k][i] = a[k][i + 1];
					a[k][i + 1] = 0;
				}
	    	}
	    	ya=0;
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
        if(ch == 122){ //按Z 
        	endgame();
		}
        if(ch == 120){//按x
	        if(a[ud][rl/2]!=0){//該格不為0 
	        	ram = a[ud][rl / 2];
	        	score = change(rl / 2,ud,a[ud][rl / 2]);
	        	if (score != 1){
	        		sum += score * (score - 1);
		           	redraw();
		          	Sleep(500);
		        	drop();
		        	redraw();	
				}
				else {
					a[ud][rl / 2] = ram;
					score = 0;
					redraw();
				}
				if(a[size-1][0]==0){
					endgame();
				}
			}else{
				endgame();
		    }
		}
		if(ch == 99){ // 按C 
			redraw();
		}
    }
}

void endgame(){
	Clr();
	if(a[size-1][0]==0){
	    gotoxy(28,1);
		cout << "Perfect Clear!";
	}
					
	gotoxy(27,3);
	cout<<"Your score is: "<<sum<<" !";
	gotoxy(26,5);
	system("pause");
	Clr();
	gotoxy(17,20);
   	cout<<"last score: "<<sum;
	startmenu();
}

void gotoxy(int xpos, int ypos){
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

void Clr(){
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
