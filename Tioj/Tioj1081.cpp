#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int pic[1010][1010];

void move(int y,int x,int len,int wid){
	while(pic[y][x]){
		pic[y][x] = 0;
		if(y && pic[y - 1][x]) move(y - 1,x,len,wid);
		if(y != wid && pic[y + 1][x]) move(y + 1,x,len,wid);
		if(x && pic[y][x - 1]) move(y,x - 1,len,wid);
		if(x != len && pic[y][x + 1]) move(y,x + 1,len,wid);
		if(y && x && pic[y - 1][x - 1]) move(y - 1,x - 1,len,wid);
		if(y && x != len && pic[y - 1][x + 1]) move(y - 1,x + 1,len,wid);
		if(y != wid && x && pic[y + 1][x - 1]) move(y + 1,x - 1,len,wid);
		if(y != wid && x != len && pic[y + 1][x + 1]) move(y + 1,x + 1,len,wid);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int len,wid;
	while(cin >> wid >> len){
		if(!wid && !len) break;
		memset(pic,0,sizeof(pic));
		string g;
		for(int i = 1;i <= wid;i++){
			cin >> g;
			for(int j = 1;j < len;j++){
				pic[i][j] = g[j - 1] - '0';
			}
		}
		int times = 0;
		for(int i = 0;i <= wid;i++){
			for(int j = 0;j <= len;j++){
				if(pic[i][j]){
					move(i,j,len,wid);
					times++;
				} 
			}
		}
		cout << times << endl;
	}
	return 0;
}
