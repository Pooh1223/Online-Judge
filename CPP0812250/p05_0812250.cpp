//File Name: p05_0812250.cpp
//Author: 林澤宇
//Email Address: leo891223@gmail.com
//Assignment Number: 05
//Description: A program helps you find the right temperature
//Last Changed: 10/27, 2019
//(i) difficulty encountered?
//None
//(ii) anything special?
//I provide two additional functions: (1) input check
//(2) avoid accidentally end the program
#include <iostream>
#include <string>
using namespace std;

bool contain258(int);
void contiCheck(string&);

int main(){
	int num = 0,temp = 0;
	string next = "",sure = "";

	cout << "This program helps you find out the nearest unbroken number.\n\n";

	do{
		do{
			cout << "\nPlease input oven temperature (an integer less than 1000): ";
			cin >> num;
		}while(num >= 1000 || num < 0);

		cout << "\n";

		if(!contain258(num)){
			cout << num << "\n";
		} else {
			temp = num - 1;

			while(contain258(temp)){
				temp--;
			}
			cout << temp << " ";

			temp = num + 1;

			while(contain258(temp)){
				temp++;
			}
			cout << temp << "\n";
		}

		//check if user want to input again
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

	//system("PAUSE");
	return 0;
}

bool contain258(int num){
	int hundred = num / 100;
	int ten = (num / 10) % 10;
	int one = num % 10;

	if(hundred == 2 || hundred == 5 || hundred == 8){
		return 1;
	} else if(ten == 2 || ten == 5 || ten == 8){
		return 1;
	} else if(one == 2 || one == 5 || one == 8){
		return 1;
	} else {
		return 0;
	}
}

void contiCheck(string& next){
	next = "";
	while(next != "Y" && next != "N"){
		cout << "You can only input Y or N\n";
		cout << "Please input again : ";
		cin >> next;
		cout << "\n";
	}
}
