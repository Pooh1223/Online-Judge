#include <bits/stdc++.h>
using namespace std;

char chg[] = {"abcdefgh"};
int dx[] = {1,2,-1,-2,1,2,-2,-1};
int dy[] = {-2,-1,-2,-1,2,1,1,2};
int board[10][10];

bool boom(int x,int y){
	return x < 0 || x >= 8 || y < 0 || y >= 8;
}

int main(){
	string st,ed;
	while(cin >> st >> ed){
		memset(board,0,sizeof(board));
		if(st == ed){
			cout << "To get from " << st << " to " << ed
						<< " takes 0 knight moves.\n"; 
			continue;
		}
		int stx = 8 - st[1] + '0',edx = 8 - ed[1] + '0',sty,edy;
		for(int i = 0;i < 8;++i){
			if(st[0] == chg[i]) sty = i;
			if(ed[0] == chg[i]) edy = i;
		}
		queue<int> qx,qy;
		qx.push(stx); qy.push(sty);
		bool end = 0;
		
		while(!qx.empty() && !end){
			int x = qx.front();
			qx.pop();
			int y = qy.front();
			qy.pop();
			int cnt = board[x][y];

			for(int i = 0;i < 8 && !end;++i){
				int tx = x + dx[i];
				int ty = y + dy[i];
				if(!boom(tx,ty) && !board[tx][ty]){
					board[tx][ty] = cnt + 1;
					if(tx == edx && ty == edy){
						end = 1;

						cout << "To get from " << st << " to " << ed
						<< " takes " << board[tx][ty] << " knight moves.\n";

						break;
					}
					qx.push(tx); qy.push(ty);
				}
			}
		}
	}

	return 0;
}