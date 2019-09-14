#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int day;
	while(cin >> day){
		if(day == 0) break;
		int sum = 0,sumc = 0;
		int times = 0;
		int re[100000];
		memset(re,0,sizeof(re));
		while(day--){
			int c;
			cin >> c;
			if(c == 0) continue;
			sumc += c;
			int max = 0,min = 1000001,pos1,pos2;
			for(int i = 0;i < (sumc - (times * 2));i++){
				if(!re[i]) cin >> re[i]; 
				if(re[i] > max){
					max = re[i];
					pos1 = i;
				} 
				if(re[i] < min){
					min = re[i];
					pos2 = i;
				}
			}
				sum += (max - min);
				re[pos1] = 0;
				re[pos2] = 0;
				times++;
			}
			cout << sum << endl;
			sum = 0;
			sumc = 0;
		}
		return 0;
	}
