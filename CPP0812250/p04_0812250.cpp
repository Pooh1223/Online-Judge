//File Name: p04_0812250.cpp
//Author: 林澤宇
//Email Address: leo891223@gmail.com
//Assignment Number: 04
//Description: A program helps you calculate your phone bill.
//Last Changed: 10/27, 2019
//(i) difficulty encountered?
//None
//(ii) anything special?
//I provide two additional functions: (1) input check
//(2) avoid accidentally end the program
#include <iostream>
#include <string>
using namespace std;

void contiCheck(string&);
void printBill(int,int,int,int);

int main(){
	string next = "";

	cout << "It's a program that helps you to calculate your bill\n\n";

	do{
		//n for how many input data
		int times,type1money = 0,type1sec = 0,type2sec = 0,type3sec = 0,cnt = 0;

		cout << "First, input a number of entries of your bill (an integer larger than 0) : ";

		//check the input
		do{	
			if(cnt) cout << "Please follow the input format!\n";
			cin >> times;
			cnt++;
		}while(times <= 0);
		
		cnt = 0;

		cout << "\n\nEvery month you have to pay for monthly fee 469\n";
		cout << "There are 3 types of call\n\n";
		cout << "1 : Intra-Network\n";
		cout << "first 5 min of each is free\n";
		cout << "after 5 min 0.05/sec\n\n";
		cout << "2 : Inter-Network\n";
		cout << "25 min free/month\n";
		cout << "after 25 min 0.1/sec\n\n";
		cout << "3 : Fixed-Lines\n";
		cout << "10 min free/month\n";
		cout << "after 10 min 0.1/sec\n\n";
		cout << "Please follow the input instructure to get your total fee\n";

		while(times--){
			cout << "\n" << times + 1 << " data remain to input\n\n";

			int type,sec;
			
			cout << "input your call type by above instructure (1,2 or 3) : ";

			//check the input
			do{	
				if(cnt) cout << "Please follow the input format!\n";
				cin >> type;
				cnt++;
			}while((type != 1 && type != 2 && type != 3));

			cnt = 0;

			cout << "input your length of this call (unit : sec) (an integer larger than 0) : ";

			//check the input
			do{	
				if(cnt) cout << "Please follow the input format!\n";
				cin >> sec;
				cnt++;
			}while(sec < 0);

			cnt = 0;

			if(type == 1){
				type1sec += sec;
				if(sec > 300) type1money += int((sec - 300) * 0.05 + 0.5);
			} else if(type == 2){
				type2sec += sec;
			} else {
				type3sec += sec;
			}
		}
		
		printBill(type1sec,type2sec,type3sec,type1money);

		//check if user want to input again
		string sure = "";
		do{
			
			cout << "If you want to input another bill ,enter Y\n";
			cout << "If you want to end this program ,enter N\n";
			contiCheck(next);			

			if(next == "Y") cout << "You choose to input again\n\n";	
			else cout << "You choose to end\n\n";

			cout << "Are you sure you want to input again ?\n";

			contiCheck(sure);

		}while(sure == "N");

	}while(next == "Y");
	
	return 0;
}

//constrain user input
void contiCheck(string& next){
	next = "";
	while(next != "Y" && next != "N"){
		cout << "You can only input Y or N\n";
		cout << "Please input again : ";
		cin >> next;
		cout << "\n";
	}
}

void printBill(int type1sec,int type2sec,int type3sec,int type1money){

	cout << "\n\nTotal time : \n";
	cout << "Intra-Network : " << type1sec << " secs\n";
	cout << "Inter-Network : " << type2sec << " secs\n";
	cout << "Fixed-Lines : " << type3sec << " secs\n";
	cout << "Total secs : " << type1sec + type2sec + type3sec << "\n";

	int type2money = 0,type3money = 0;

	if(type2sec > 1500) type2money = int((type2sec - 1500) * 0.1 + 0.5);
	if(type3sec > 600) type3money = int((type3sec - 600) * 0.1 + 0.5);

	cout << "\nPayment : \n";
	cout << "Intra-Network : " << type1money << "\n";
	cout << "Inter-Network : " << type2money << "\n";
	cout << "Fixed-Lines : " << type3money << "\n\n";
	cout << "Total payment : " << 469 + type1money + type2money + type3money << "\n";

}