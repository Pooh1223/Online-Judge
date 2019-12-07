//File Name: p06_0812250.cpp
//Author: 林澤宇
//Email Address: leo891223@gmail.com
//Assignment Number: 06
//Description: A program tells you what day it is
//Last Changed: 11/25, 2019
//(i) difficulty encountered?
//None
//(ii) anything special?
//I provide two additional functions: (1) input check
//(2) print calendar of that month
//(3) deal with string month input
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

void getInput(int &month,int &day,int &year); 
bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month,int year);
void printCalendar(int dayOfWeek,int day,int month,int year);
void contiCheck(string&);

void setColor(int color = 7){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}

int main(){
	string next = "",sure = "";
	int month = 0,day = 0,year = 0,dayOfWeek = 0;

	cout << "This is a program that tells you what day it is.\n";


	do{
		getInput(month,day,year);

		dayOfWeek = day + getMonthValue(month,year)
			+ getYearValue(year) + getCenturyValue(year);

		cout << "It's ";
		switch(dayOfWeek % 7){
			case 0:
				cout << "Sunday\n";
				break;
			case 1:
				cout << "Monday\n";
				break;
			case 2:
				cout << "Tuesday\n";
				break;
			case 3:
				cout << "Wednesday\n";
				break;
			case 4:
				cout << "Thursday\n";
				break;
			case 5:
				cout << "Friday\n";
				break;
			case 6:
				cout << "Saturday\n";
				break;
		}

		printCalendar(dayOfWeek,day,month,year);

		do{
			
			cout << "\nIf you want to input another temperature ,enter Y\n";
			cout << "If you want to end this program ,enter N\n\n";
			contiCheck(next);			

			if(next == "Y") cout << "You choose to input again\n\n";	
			else cout << "You choose to end\n\n";

			cout << "Are you sure you want to input again ?\n";

			contiCheck(sure);

		}while(sure == "N");

	}while(next == "Y");

	return 0;
}

void getInput(int &month,int &day,int &year){
	cout << "Follow the input format: M D Y\n";
	cout << "Ex : 7 4 2008 and July 4 2008 both represent July 4 2008\n\n\n";

	string monthStr = "";
	cin >> monthStr >> day >> year;

	if(monthStr == "January" || monthStr == "1"){
		month = 1;
	} else if(monthStr == "February" || monthStr == "2"){
		month = 2;
	} else if(monthStr == "March" || monthStr == "3"){
		month = 3;
	} else if(monthStr == "April" || monthStr == "4"){
		month = 4;
	} else if(monthStr == "May" || monthStr == "5"){
		month = 5;
	} else if(monthStr == "June" || monthStr == "6"){
		month = 6;
	} else if(monthStr == "July" || monthStr == "7"){
		month = 7;
	} else if(monthStr == "August" || monthStr == "8"){
		month = 8;
	} else if(monthStr == "Semtember" || monthStr == "9"){
		month = 9;
	} else if(monthStr == "October" || monthStr == "10"){
		month = 10;
	} else if(monthStr == "November" || monthStr == "11"){
		month = 11;
	} else if(monthStr == "December" || monthStr == "12"){
		month = 12;
	}
}

bool isLeapYear(int year){
	return !(year % 400) || (!(year % 4) && year % 100);
}

int getCenturyValue(int year){
	int firstDigit = 0,secondDigit = 0,centuryValue = 0;

	firstDigit = year / 1000;
	secondDigit = (year / 100) % 10;
	centuryValue = 10 * firstDigit + secondDigit;

	return (3 - (centuryValue % 4)) * 2;
}

int getYearValue(int year){
	int yearValue = 0;

	yearValue = year % 100;

	return yearValue + (yearValue / 4);
}

int getMonthValue(int month,int year){
	bool leapYear = isLeapYear(year);

	if((month == 1 && !leapYear) || month == 10){
		return 0;
	} else if((month == 2 && !leapYear) || month == 3 || month == 11){
		return 3;
	} else if((month == 1 && leapYear) || month == 4 || month == 7){
		return 6;
	} else if(month == 5){
		return 1;
	} else if(month == 6){
		return 4;
	} else if((month == 2 && leapYear) || month == 8){
		return 2;
	} else if(month == 9 || month == 12){
		return 5;
	}
}

void printCalendar(int dayOfWeek,int day,int month,int year){
	cout << "\n";

	int tempDay = day;
	while(tempDay > 1){
		tempDay--;
		dayOfWeek = (dayOfWeek + 6) % 7;
	}

	int totalDay = 0;

	if(month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12) totalDay = 31;
	else if(month == 4 || month == 6 || month == 9 || month == 11) totalDay = 30;
	else if(month == 2 && isLeapYear(year)) totalDay = 29;
	else totalDay = 28;

	cout << "year : " << year << " , month : " << month << "\n\n";
	cout << "| Sun | Mon | Tue | Wed | Thu | Fri | Sat |\n";

	//adjust position
	for(int i = 0;i < dayOfWeek;++i){
		cout << "      ";
	}

	// print
	for(int i = 1;i <= totalDay;++i){
		if(i == day) setColor(12);

		cout << setw(5) << i << " ";

		if(dayOfWeek == 6) cout << "\n";
		dayOfWeek = (dayOfWeek + 8) % 7;

		if(i == day) setColor();
	}

	cout << "\n\n";
}

void contiCheck(string& next){
	next = "";
	while(next != "Y" && next != "N"){
		cout << "You can only input Y or N\n";
		cout << "Please input : ";
		cin >> next;
		cout << "\n";
	}
}

/* | Sun | Mon | Tue | Wed | Thu | Fri | Sat |
       1     2     3     4     5     6     7
       8	 9	  10	11    12    13    14
      15    16    17    18    19    20    21
      22    23    24    25    26    27    28
      29    30    31*/
