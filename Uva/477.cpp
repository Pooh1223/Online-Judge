#include <bits/stdc++.h>
using namespace std;

struct shape{
	int id;
	char type;
	double a,b,c,d;
}fig[13];

int main(){
	char c;
	int pos = 0;
	while(cin >> c){
		if(c == '*') break;

		if(c == 'r'){
			fig[pos].type = 'r';
			cin >> fig[pos].a >> fig[pos].b >> fig[pos].c >> fig[pos].d;
		} else {
			fig[pos].type = 'c';
			cin >> fig[pos].a >> fig[pos].b >> fig[pos].c;
		}

		fig[pos].id = pos;
		pos++;
	}
	double x,y;
	for(int k = 1;cin >> x >> y;++k){
		if(x == 9999.9 && y == 9999.9) break;
		bool ok = 0;

		for(int i = 0;i < pos;++i){
			if(fig[i].type == 'r'){
				if(x > fig[i].a && x < fig[i].c && y > fig[i].d && y < fig[i].b){
					ok = 1;
					cout << "Point " << k << " is contained in figure " << fig[i].id + 1 << "\n";
				}
			} else {
				if((x - fig[i].a) * (x - fig[i].a) + (y - fig[i].b) * (y - fig[i].b) < fig[i].c * fig[i].c){
					ok = 1;
					cout << "Point " << k << " is contained in figure " << fig[i].id + 1 << "\n";
				}
			}
		}

		if(!ok) cout << "Point " << k << " is not contained in any figure\n";
	}
	return 0;
}