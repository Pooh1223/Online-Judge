#include <iostream>
using namespace std;

int main(){
	bool a,b,c,d;
	a = b = c = d = false;
	for(int i = 1;i <= 16;++i){
		printf("%d : \n",i);
		printf("%d %d %d %d %d\n",(a || !d),(!a || b),(!b || c),(!a || !b || !c),(a || !c || d));
	}
	return 0;
}