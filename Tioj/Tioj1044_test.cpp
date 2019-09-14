#include <iostream>
using namespace std;

int g(int num,int btlimit,int toplimit){
	int i;
	cout << "If the number I guess isn't smaller than you're thinking,input 1" << endl;
	cout << "Else ,enter 0" << endl;
	cout << num << endl;
	cin >> i;
	if (i == 0){
		if(toplimit - num == 1) return num + 1;
		return g((num + toplimit) / 2,num,toplimit);
	}
	else {
		if(toplimit - num == 1) return num;
		return g((btlimit + num) / 2,btlimit,num);
	}
}

int main(){
	int n,ck;
	cout << "Please enter a limit,and think one number in the range" << endl;
	cin >> n;
	cout << g((1 + n) / 2,1,n) << endl;
	return 0;
}
