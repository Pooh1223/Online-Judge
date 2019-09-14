#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char game[10010];
	while(scanf("%s",game) != EOF){
		int len = strlen(game);
		int out = 0;
		int score[2];
		memset(score,0,sizeof(score));
		int base[5];
		memset(base,0,sizeof(base)); 
		for(int i = 0,j = 0;i < len;i++){
			if(game[i] == 'K' || game[i] == 'O'){
				out++;
				if(!(out % 3)){
					memset(base,0,sizeof(base));
					j++;
				}
			}
			else if(game[i] == 'S'){
				score[j % 2] += base[3];
				base[3] = base[2];
				base[2] = base[1];
				base[1] = 1;
			}
			else if(game[i] == 'D'){
				score[j % 2] += base[3] + base[2];
				base[3] = base[1];
				base[2] = 1;
				base[1] = 0;
			}
			else if(game[i] == 'T'){
				score[j % 2] += base[3] + base[2] + base[1];
				base[3] = 1;
				base[2] = 0;
				base[1] = 0;
			}
			else if(game[i] == 'H'){
				score[j % 2] += base[3] + base[2] + base[1] + 1;
				memset(base,0,sizeof(base));
			}
			else if(game[i] == 'W'){
				int k = 1;
				for(;k < 4;k++) if(!base[k]) break;
				if(k == 4) score[j % 2]++;
				else for(int q = 1;q <= k;q++) base[q] = 1; 
			}
		}
		cout << score[0] << " " << score[1] << endl;
	}
	
	return 0;
}
