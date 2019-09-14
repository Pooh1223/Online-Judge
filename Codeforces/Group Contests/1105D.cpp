#include <bits/stdc++.h>
using namespace std;

struct grid_num{
	int x,y;
};
char mp[1003][1003];
int pcnt[10]; //participater
int speed[10];
int dx[]{0,0,-1,1};
int dy[]{1,-1,0,0};
queue<grid_num> q[10];

bool boom(int x,int y,int mxx,int mxy){
	return (x < 0 || y < 0 || x >= mxx || y >= mxy);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m,p,empty_grid = 0;
	cin >> n >> m >> p;
	for(int i = 1;i <= p;++i){
		cin >> speed[i];
		if(speed[i] > 10000) speed[i] = 10000;
	} 
	for(int i = 0;i < n;++i){
		for(int j = 0;j < m;++j){
			cin >> mp[i][j];
			if(mp[i][j] == '.') empty_grid++;
			else if(mp[i][j] != '#'){ //start point
				int now = mp[i][j] - '0';
				pcnt[now]++; 
				q[now].push(grid_num{i,j}); //push start point
			}
		}
	}
	int turn = 1;
	while(empty_grid != 0){
		if(turn > p) turn -= p;
		int times = speed[turn];
		//cout << times << "\n";
		if(q[turn].empty()){
			turn++;
			continue;
		}
		while(times--){ //expand
			int back = q[turn].size();
			if(back == 0) break;
			while(back--){ // run through all points
				grid_num now;
				now = q[turn].front();
				q[turn].pop();
				for(int i = 0;i < 4;++i){ //conquer
					int tx = now.x + dx[i];
					int ty = now.y + dy[i];
					//cout << "tx : " << tx << " ty : " << ty << "\n";
					//cout << !(tx < 0 || ty < 0 || tx >= n || ty >= m) << "\n";
					//cout << (mp[tx][ty] == '.') << "\n";
					if(!boom(tx,ty,n,m) && mp[tx][ty] == '.'){
						//cout << "in!!!!\n";
						mp[tx][ty] = turn + '0';
						pcnt[turn]++;
						q[turn].push(grid_num{tx,ty});
						empty_grid--;
					}
				}
				if(empty_grid == 0) break;
			}
			if(empty_grid == 0) break;
			//cout << "jizz\n";
			// for(int i = 0;i < n;++i){
			// 	for(int j = 0;j < m;++j){
			// 		cout << mp[i][j];
			// 	}
			// 	cout << "\n";
			// }
			// cout << "\n";
		}
		turn++;
		bool ck = 0;
		for(int i = 1;i <= p;++i){
			if(q[i].size()) ck = 1;
		}
		if(!ck) break;
		/* avoid this ###
			          #.#
		              ###  */
	}


	for(int i = 1;i <= p;++i) cout << pcnt[i] << " ";

	// for(int i = 0;i < n;++i){
	// 	for(int j = 0;j < m;++j){
	// 		cout << mp[i][j];
	// 	}
	// 	cout << "\n";
	// }
	
	return 0;
}