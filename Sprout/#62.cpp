#include <iostream>
#include <cstring>
using namespace std;
int board[20][20],empty[150],ans[100],cnt = 0;
bool used[20],ck = 0,ck2 = 0;
bool check(){
	for(int i = 0;i < 9;++i){
		for(int j = 0;j < 9;++j){
			if(board[i][j] != 0){
				if(used[board[i][j]] == 1){
					//printf("1 : board[%d][%d] : %d\n",i,j,board[i][j]);
					return 1;
				} 
				else used[board[i][j]] = 1;
			}
		}
		memset(used,0,sizeof(used));
	}
	memset(used,0,sizeof(used));
	for(int i = 0;i < 9;++i){
		for(int j = 0;j < 9;++j){
			if(board[j][i]){
				if(used[board[j][i]] == 1){
					//printf("2 : board[%d][%d] : %d\n",j,i,board[j][i]);
					return 1;
				} 
				else used[board[j][i]] = 1;
			}
		}
		memset(used,0,sizeof(used));
	}
	return 0;
}
void cut(int x,int y){
	memset(used,0,sizeof(used));
	for(int i = 0;i < 9;++i){
		used[board[x][i]] = 1;
		used[board[i][y]] = 1;
	}
	for(int i = x / 3 * 3;i < x / 3 * 3 + 3;++i)
		for(int j = y / 3 * 3;j < y / 3 * 3 + 3;++j)
			used[board[i][j]] = 1;
}
void back(int N,int n){
	if(n == N && !ck){
		int g = 0;
		for(int i = 0;i < 9;++i)
			for(int j = 0;j < 9;++j)
				cout << board[i][j];

		cout << "\n";
		ck = 1;
		return;
	}
	else if(!ck){
		for(int j = 1;j < 10;++j){
			cut(empty[n] / 10,empty[n] % 10);
			if(!used[j]){
				used[j] = 1;
				board[(empty[n] / 10)][(empty[n] % 10)] = j;
				ans[n] = j;
				back(N,n + 1);
				board[(empty[n] / 10)][(empty[n] % 10)] = 0;
				used[j] = 0;
				if(ck) return;
			}
		}
	}
}
int main(){
	cin.tie(0);
	while(1){
		for(int i = 0;i < 9 && !ck;++i){
			for(int j = 0;j < 9 && !ck;++j){
				char a;
				cin >> a;
				if(a == '\n'){
					--j;
					continue;
				}
				if(a == '.'){
					board[i][j] = 0;
					empty[cnt++] = i * 10 + j;
				} 
				else if(a == 'd'){
					ck = 1;
					ck2 = 1;
				} 
				else board[i][j] = (int)a - '0';
			}
		}
		if(ck2) break;
		if(check());
		else back(cnt,0);
		if(!ck) cout << "No solution.\n";
		ck = 0;
		memset(used,0,sizeof(used));
		memset(empty,0,sizeof(empty));
		cnt = 0;
	}
	return 0;
}