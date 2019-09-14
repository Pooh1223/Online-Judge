#include <bits/stdc++.h>
using namespace std;
bitset<1000003> ice;
int r,c;
int a[1000006],b[1000006];
inline int h(int x,int y){
	if(x < 1 || x > r || y < 1 || y > c) return 1000002;
	return (x - 1) * c + y;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> r >> c;
	for(int i = 1;i <= r;++i){
		for(int j = 1;j <= c;++j){
			bool jizz; cin >> jizz;
			ice[h(i,j)] = jizz;
		}
	}
	for(int i = 1;i <= r;++i){
		for(int j = 1;j <= c;++j){
			if(j == 1) continue;
			a[h(i,j)] = a[h(i,j - 1)];
			if(ice[h(i,j)] && ice[h(i,j - 1)]) a[h(i,j)]++;
		}
	}
	for(int j = 1;j <= c;++j){
		for(int i = 1;i <= r;++i){
			if(i == 1) continue;
			a[h(i,j)] += a[h(i - 1,j)];
			b[h(i,j)] = b[h(i - 1,j)];
			if(ice[h(i,j)] && ice[h(i - 1,j)]) b[h(i,j)]++;
		}
	}
	for(int i = 1;i <= r;++i){
		for(int j = 1;j <= c;++j){
			if(j != 1)
				b[h(i,j)] += b[h(i,j - 1)];
		}
	}
	int q;
	cin >> q;
	while(q--){
		int r1,c1,r2,c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int rr = a[h(r2,c2)] - a[h(r2,c1)] - a[h(r1 - 1,c2)] + a[h(r1 - 1,c1)];
		int cc = b[h(r2,c2)] - b[h(r2,c1 - 1)] - b[h(r1,c2)] + b[h(r1,c1 - 1)];
		cout << rr + cc << "\n";
	}
	return 0;
}