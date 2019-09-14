#include <iostream>
#include <string> 
using namespace std;

short end(short x,short array[][x]);

int main(){
	short n,length,width;
	cin >> n >> length >> width;
	string g1,g2;
	//short pic[width][length];
	for(short i = 0,t[width][length];i < length;i++){
		if(i == 0 || i == length - 1){
			cin >> g1;
			for(short j = 0;j < g1.length();j++){
				t[i][j] = (short)g1[j] - '#';	
			}
		} 
		else {
			cin >> g2;
			if (g1 == g2){
				length--;
				continue;
			} 
			else{
				for(short j = 0;j < g2.length();j++){
					t[i][j] = (short)g2[j] - '#';	
				}	
			}	
		}
	}
	short pic[width][length];
	short side[n];
	for(short i = 0,j = 0;i < width;i++){
		if(!pic[0][i]){
			side[j] = i;
			j++;
		}
	}
	short now = 0;
	for(short order = 1;order <= n;order++){
		for(short down = 1;;){
			if(side[now] == 0){
				for(;down < length;down++){
					if(!pic[down][1]){
						now++;
						down++;
						break;
					}
				}
			}
			else if(side[now] == width - 1){
				for(;down < length;down++){
					if(!pic[down][width - 2]){
						now--;
						down++;
						break;
					}
				}
			}
			else {
				for(;down < length;down++){
					if(!pic[down][side[now] - 1]){
						now--;
						down++;
						break;
					}
					else if(!pic[down][side[now] + 1]){
						now++;
						down++;
						break;
					}
				}
			}
			if(down == length){
				cout << now + 1 << " ";
				break;
			} 
		}
		now = order;
	}
	return 0;
} 
