#include <iostream>
#include <windows.h>
using namespace std;

//functions
void startmenu();
//tools
void SetColor(int,int);
void gotoxy(int,int);
void Clr();

int map[100][100];
int length = 0,width = 0,minenum = 0;

int main(){
	startmenu();
	return 0;
}

void startmenu(){
	gotoxy(27,3);
	SetColor(4,7);
	cout << "Please input your mode number." << endl;
	cout << "(1) Easy (9 * 9)" << endl;
	cout << "(2) Medium (16 * 16)" << endl;
	cout << "(3) Hard (30 * 16)" << endl;
	cout << "(4) Your Choice! (Maxlen : 100 , Maxwid : 100 , Minmine : 10)" << endl;
	int choice;
	cin >> choice;
	switch(choice){
		case 1 :
			length = 9;
			width = 9;
			break;
		case 2 : 
			length = 16;
			width = 16;
			break;
		case 3 : 
			length = 30;
			width = 16;
			break;
		case 4 : 
			cout << "Please input your length." << endl;
			cin >> length;
			cout << "Please input your width." << endl;
			cin >> width;
			cout << "Last,we need you to input the amount of mines." << endl;
			cin >> minenum;
			break;
			
		default : 
			cout << "This order is undifined.";
	} 
}

void SetColor(int f=7,int b=0){
    unsigned short ForeColor=f+16*b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
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
