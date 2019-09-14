#include <iostream>
using namespace std;

int main(){
	
	int a,ans[1000];
	int j = 0;
	while(cin >> a){
		
	for(;;j++){
		
		if (a / 2 > 0){
		ans[j] = a % 2;	
		a = a / 2;
		continue;		
		}
		if (a / 2 == 0 && a % 2 == 1){
			ans[j] = 1;
			break;
		}
		else if (a / 2 == 0 && a % 2 == 0){
			ans[j] = 0;
			break;
		}
	}	
	for(;j >= 0;j--){
		cout << ans[j];
		if (j == 0)
		cout << endl;
	}
		j = 0;
	}
	
	return 0;
} 
