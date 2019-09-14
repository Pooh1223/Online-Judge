#include <iostream> 
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
		int check = 0;
		if((a + c) == b + b) check++;
		if((a * c) == (b * b) && a && b && c) check += 2;
		
		switch(check){
			case 0 :
				cout << "normal" << endl;
				break;
			case 1 :
				cout << "arithmetic" << endl;
				break;
			case 2 :
				cout << "geometric" << endl;
				break;
			case 3 : 
				cout << "both" << endl;
				break;
	}
	return 0;
}
