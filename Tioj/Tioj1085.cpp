#include <bits/stdc++.h>
using namespace std;
struct pre{
	int px,py,pz;
}pr[53][53][53];
bool used[53][53][53];
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
int fx,fy,fz;
bool boom(int x,int y,int z){
	if(x > fx || x < 1 || y > fy || y < 1 || z > fz || z < 1) return 1;
	else return 0;
}
void bfs(){
	queue<pre> q;
	q.push((pre){1,1,1});
	used[1][1][1] = 1;
	while(!q.empty()){
		pre a = q.front(); q.pop();
		for(int i = 0;i < 6;++i){
			int tx = a.px + dx[i];
			int ty = a.py + dy[i];
			int tz = a.pz + dz[i];
			if(!boom(tx,ty,tz) && !used[tx][ty][tz]){
				pr[tx][ty][tz].px = a.px;
				pr[tx][ty][tz].py = a.py;
				pr[tx][ty][tz].pz = a.pz;
				q.push((pre){tx,ty,tz});
				used[tx][ty][tz] = 1;
			}
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> fx >> fy >> fz;
	for(int k = 1;k <= fz;++k){
		for(int j = 1;j <= fy;++j){
			for(int i = 1;i <= fx;++i){
				cin >> used[i][j][k];
			}
		}
	}
	if(used[1][1][1] == 1 || used[fx][fy][fz] == 1) cout << "no route\n";
	else {
		bfs();
		if(!used[fx][fy][fz]) cout << "no route\n";
		else {
			vector<pre> v;
			v.push_back((pre){fx,fy,fz});
			while(pr[v.back().px][v.back().py][v.back().pz].px != 0 || pr[v.back().px][v.back().py][v.back().pz].py != 0 || pr[v.back().px][v.back().py][v.back().pz].pz != 0){
				int xx = v.back().px;
				int yy = v.back().py;
				int zz = v.back().pz;
				v.push_back((pre){pr[xx][yy][zz].px,pr[xx][yy][zz].py,pr[xx][yy][zz].pz});
			}
			for(int i = (int)v.size() - 1;i >= 0;--i){
				if(i != (int)v.size() - 1) cout << "->(" << v[i].px << "," << v[i].py << "," << v[i].pz << ")";
				else cout << "(1,1,1)";
			}
		}
	}
	return 0;
}