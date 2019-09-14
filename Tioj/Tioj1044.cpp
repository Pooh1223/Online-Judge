#include <iostream>
#include "lib1044.h"
using namespace std;

int g(int num,int btlimit,int toplimit){
	int i;
	i = Guess(num);
	if (i == 0){
		if(toplimit - num == 1) return num + 1;
		return g((num + toplimit) / 2,num,toplimit);
	}
	else {
		if(toplimit - num == 1) return num;
		return g((btlimit + num) / 2,btlimit,num);
	}
}

int main(void){
	int n,ck;
	n = Initialize();
	Report(g((1 + n) / 2,1,n));
	return 0;
}
