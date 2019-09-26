
#include <iostream>
using namespace std;

int main(){
	cout << "This program is a simulation of fire regulations.\n";
	cout << "You are asked to input 2 numbers:\n";
	cout << "The first number is the maximum room capacity,\n";
	cout << "while the second number is the number of people in this room.\n";
	cout << "Please follow this input format \n(Ex1)12 3\n(Ex2)18 7\n\n";

	string next = "";

	do{
		int roomCapacity,roomPeople;
		

		cin >> roomCapacity >> roomPeople;

		cout << "\n(echo the input) The maximum room capacity "
			 << "you entered is " << roomCapacity << ".\n";

		cout << "(echo the input) The number of people "
		 	 << "attending the meeting you entered is "
		 	 << roomPeople << ".\n\n";

		if(roomCapacity >= roomPeople){
			cout << "It is legal to hold the meeting ";

			if(roomCapacity == roomPeople)
				cout << "but\nno more additional people "
					 << "may legally attend.\n";

			else if(roomCapacity - roomPeople == 1)
				cout << "and\n1 additional person "
					 << "may legally attend.\n";

			else cout << "and\n" << roomCapacity - roomPeople 
					  << " additional people may legally attend.\n";

		} else {
			if(roomPeople - roomCapacity == 1)
				 cout << "Due to fire regulations, "
				 << "the meeting cannot be held and\n"
				 << "1 person must be excluded to meet the fire regulation.\n";

			else cout << "Due to fire regulations, "
				 << "the meeting cannot be held and\n"
				 << roomPeople - roomCapacity
				 << "people must be excluded to meet the fire regulation.\n";
		}

		cout << "Do you want to input again?\n";
		cout << "Enter 'Y' for yes , 'N' for no :\n\n";
		cin >> next;

	}while(next == "Y" || next == "y" || next == "Yes");

	return 0;
}