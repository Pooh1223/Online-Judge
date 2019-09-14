#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
char dd[] = {'N','E','S','W'};

bool mp[53][53];
int n,m;

bool boom(int x,int y){
	return x < 0 || y < 0 || x > n || y > m;
}

int main(){
	cin >> n >> m;
	int x,y;
	char d;
	while(cin >> x >> y >> d){
		int pos = 0;
		for(;pos < 4;++pos)
			if(dd[pos] == d) break;

		string s;
		cin >> s;

		bool ok = 0;

		for(int i = 0;i < s.length();++i){
			if(s[i] == 'R'){
				pos = (pos + 5) % 4;
			} else if(s[i] == 'L'){
				pos = (pos + 3) % 4;
			} else {
				if(boom(x + dx[pos],y + dy[pos])){
					if(mp[x][y]) continue;
					else {
						mp[x][y] = 1;
						cout << x << " " << y << " ";
						cout << dd[pos] << " LOST\n";
						ok = 1;
						break;
					}
				} else {
					x += dx[pos];
					y += dy[pos];
				}
			}
		}
		if(!ok){
			cout << x << " " << y << " ";
			cout << dd[pos] << "\n";
		}
	}

	return 0;
}