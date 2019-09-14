#include <bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin >> t;
	//string ans;

	for(int g = 0;g < t;++g){
		int a,b;
		cin >> a >> b;
		for(int k = 0;k < b;++k){
			int num = 1;
			for(int i = 1;i <= 2 * a - 1;++i){
				for(int j = 0;j < num;++j){
					cout << num;
					//ans += to_string(num);
				}
				if(i < a) num++;
				else num--;

				cout << "\n";
			}
			if(g != t - 1 || k != b - 1) cout << "\n";
		}

	}

	//cout << ans;

	return 0;
}