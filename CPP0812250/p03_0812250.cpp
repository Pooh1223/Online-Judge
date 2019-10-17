//File Name: p03_0812250.cpp
//Author: 林澤宇
//Email Address: leo891223@gmail.com
//Assignment Number: 03
//Description: A program allows you to see how many month you need to finish your debt.
//Last Changed: 10/16, 2019
//(i) difficulty encountered?
//Decimal processing is hard
//(ii) anything special?
//I provide one additional functions: (1) inputCheck to check if the input is legal
//(2) I allows user to input their new monthly payment if they need to
#include <bits/stdc++.h>
using namespace std;

//template for checking input
template <class T>
T inputCheck(T mn,T mx){
	T num;
	while(cin >> num){
		if(num < mn || num > mx){
			cout << "Your input is not legal!\n";
			cout << "Please input again!\n";
		} else {
			break;
		}
	}
	return num;
}

int main(){
	int price,monthlyPaid,sum,cnt = 0;
	double interestRate;
	bool check = 0;
	string next = "";

	cout << "This program is to help you figure out,\n";
	cout << "how many month you need to pay off your debt\n";
	cout << "now please input three integer\n";

	do{
		cout << "\n1. total price of new iPhone (an integer no larger than 50000): ";

		//check if it is legal input
		price = inputCheck(1,50000);

		cout << "Your input is " << price << "\n";

		cout << "\n2. interestRate (an integer X reprsenting you need an interest X%)\n";
		cout << "If you want to enter monthly interestRate, enter 0\n";
		cout << "Or if you want to enter annual interestRate, enter 1\n";
		cout << "Monthly or Annual? ";

		cin >> check;

		if(check) cout << "You choose Annual\n";
		else cout << "You choose Monthly\n";

		cout << "\nOk ,then input your interest rate (a double no larger than 100): ";

		//check if it is legal input
		interestRate = inputCheck(0.0,100.0);

		//change from per year to per month
		if(check) interestRate /= 1200.0;
		else interestRate /= 100.0;

		cout << "\nFinally,enter how much you can afford per month (an integer no larger than 50000): ";

		//check if it is legal input
		monthlyPaid = inputCheck(1,50000);

		cout << "Your input is " << monthlyPaid << "\n";

		//cout << "\nNow here are some details about your debt\n";
		sum = 0;

		//check if it is legal input
		if((double)price * interestRate >= monthlyPaid){
			cout << "Your monthly paid can only afford interest rate\n";
			cout << "So it is impossible to pay off your debt\n";
			cout << "Do you want to continue?\n";
			cout << "Y for yes, N for no\n";
			cin >> next;
			continue;
		}

		//pre calculate how many months you need 
		int p = price;
		while(p > 0){
			cnt++;

			int interestPaid = (int)(((double)p * interestRate) + 0.5);
			p -= monthlyPaid - interestPaid;
		}

		bool chg = 0;
		int newMonthlyPaid,specifyMonth;

		cout << "\nYou need to pay for " << cnt << " months\n";
		cout << "If you think it's too long,you can change your payment after specify month\n";
		cout << "Do you need that? Enter 0 for no, 1 for yes : ";
		cin >> chg;

		if(chg){
			cout << "You choose to change\n\n";
			cout << "Now please input after which month you want to change your payment\n";
			cout << "(an integer no larger than original total month) : ";

			specifyMonth = inputCheck(1,cnt);
			
			cout << "Your input is " << specifyMonth << "\n";

			cout << "\nnow please input your new monthly payment (an integer no larger than 50000): ";
			cout << "Your original payment is " << monthlyPaid << "\n";
			newMonthlyPaid = inputCheck(1,50000);

			cout << "Your input is " << newMonthlyPaid << "\n";
			cout << "Receive\n";
		} else {
			cout << "You choose not to change\n";
			cout << "Ok,here are some details about your debt\n";
		}

		for(int i = 1;price > 0;++i){
			if(i == specifyMonth) monthlyPaid = newMonthlyPaid;

			int interestPaid = (int)((double)price * interestRate + 0.5);
			sum += interestPaid;
			price -= monthlyPaid - interestPaid;

			cout << i << " Month : \n";
			cout << "interest paid this month : " << interestPaid << "\n";

			if(price < 0){
				cout << "remaining debt : 0\n\n";
				cout << "Total month : " << i << " months\n";
			} 
			else cout << "remaining debt : " << price << "\n\n";
		}

		cout << "Total interest you paid is : " << sum << "\n\n";

		cout << "Do you want to continue?\n";
		cout << "Y for yes, N for no\n";
		cin >> next;

	}while(next == "y" || next == "Y" || next == "yes");
	

	return 0;
}