#include <iostream>
#include <queue>
using namespace std;
//int val[10005];
int main(){
	int n,m;
	cin >> n >> m;
	int stx,sty,edx,edy;
	cin >> stx >> sty >> edx >> edy;
	g[stx][sty] = -1;
	int k;
	cin >> k;
	//for(int i = 0;i < k;++i) cin >> val[i];
	for(int i = 0;i < k;++i){
		int jizz;
		cin >> jizz;
		if(i == 0){
			
		}
	}
	//queue<int> q;
	//q.push(stx); q.push(sty);
	//int b = 0;
	/*while(!q.empty()){
		if(b == k) break;
		int sz = q.size() / 2;
		while(sz--){
			int tx = q.front(); q.pop();
			int ty = q.front(); q.pop();
			int dx[4],dy[4];
			dx[0] = tx + (val[b] % n) > n - 1 ? tx + (val[b] % n) - (n - 1) : tx + (val[b] % n); dy[0] = ty;
			dx[1] = tx - (val[b] % n) < 0 ? tx - (val[b] % n) + n - 1 : tx - (val[b] % n); dy[1] = ty;
			dx[2] = tx; dy[2] = ty + (val[b] % m) > m - 1 ? ty + (val[b] % m) - (m - 1) : ty + (val[b] % m);
			dx[3] = tx; dy[3] = ty - (val[b] % m) < 0 ? ty - (val[b] % m) + m - 1 : ty - (val[b] % m);
			for(int i = 0;i < 4;++i){
				printf("dx[%d] : %d,dy[%d] : %d\n",i,dx[i],i,dy[i]);
				q.push(dx[i]); q.push(dy[i]);
			}
		}
		++b;
	}*/
	//if(b == k){
		bool ck = 0;
		while(!q.empty()){
			int xx = q.front(); q.pop();
			int yy = q.front(); q.pop();
			if(xx == edx && yy == edy){
				ck = 1;
				break;
			} 
		}
		if(ck) cout << "YES\n";
		else cout << "NO\n";
	//}
	return 0;
}