#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	while(cin >> t){
		if(!t) break;
		int cx,cy;
		cin >> cx >> cy;
		for(int i = 0;i < t;++i){
			int x,y;
			cin >> x >> y;
			if(cx == x || cy == y) cout << "divisa";
			else if(cx > x && cy > y) cout << "SO";
			else if(cx < x && cy > y) cout << "SE";
			else if(cx > x && cy < y) cout << "NO";
			else if(cx < x && cy < y) cout << "NE";
			cout << "\n";
		}
	}
	return 0;
}