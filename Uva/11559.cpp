#include <bits/stdc++.h>
using namespace std;

int main(){

	long long n,b,h,w;
	string ans;

	while(cin >> n >> b >> h >> w){
		long long mn = 1e9,oneNight,emt;

		for(int i = 0;i < h;++i){
			cin >> oneNight;
			for(int j = 0;j < w;++j){
				cin >> emt;
				if(emt >= n) mn = min(mn,oneNight * n);
			}
		}

		if(mn > b) cout << "stay home\n";
		else cout << mn << "\n";
	}

	return 0;
}