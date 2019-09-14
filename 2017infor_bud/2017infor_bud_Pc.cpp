#include <iostream>
typedef unsigned __int8 int8;
using namespace std;


int main(){
	int8 n,length,width;
	cin >> n >> length >> width;
	char g;
	int8 pic[width][length];
	for(int8 i = 0;i < length;i++){
		for(int8 j = 0;j < width;j++){
			cin >> g;
			pic[i][j] = (int8)g - '#';
		}
	}
	int8 side[n];
	for(int8 i = 0,j = 0;i < width;i++){
		if(!pic[0][i]){
			side[j] = i;
			j++;
		}
	}
	int8 now = 0;
	for(int8 order = 1;order <= n;order++){
		for(int8 down = 1;;){
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
