#include <iostream>
#include <cstring>
using namespace std;

int fear[10];

int non(int x){
	int i = x,num[8];
	bool check = 0;
	memset(num,0,sizeof(num));
	do{
		int j = 0;
		num[j] = x % 10;
		x = x / 10;
		if(!fear[num[j]]) check = 1;
		j++;
	}while(x);
	if(check) return non(i + 1);
	else return i;
}

int main(){
	int t;
	cin >> t;
		while(t--){
			int r;
			cin >> r;
			char m = '0';
			int sum = 0;
			for(int i = 0;i < 10;i++){
				cin >> m;
				fear[i] = (int)m - '0';
				sum += fear[i];		
			}
			if(sum == 1 && fear[0] == 1);
			else cout << non(r) << endl;
			sum = 0; 
		}
	return 0;
} 
