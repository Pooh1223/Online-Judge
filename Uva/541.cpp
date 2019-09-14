#include <bits/stdc++.h>
using namespace std;

int num[103][103];

vector<int> vr,vc;

int main(){

	int n;

	while(cin >> n){
		if(!n) break;
		vr.clear(); vc.clear();
		
		for(int i = 1;i <= n;++i)
			for(int j = 1;j <= n;++j)
				cin >> num[i][j];

		for(int i = 1;i <= n;++i){
			int row = 0,col = 0;
			for(int j = 1;j <= n;++j){
				row += num[i][j];
				col += num[j][i];
			}
			if(row % 2) vr.push_back(i);
			if(col % 2) vc.push_back(i);
		}

		if(vr.empty() && vc.empty()) cout << "OK\n";
		else if(vr.size() == 1 && vc.size() == 1)
			cout << "Change bit (" << vr[0] << "," << vc[0] << ")\n";
		else cout << "Corrupt\n";
	}

	return 0;
}