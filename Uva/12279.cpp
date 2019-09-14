#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,cnt = 1;
	while(cin >> n && n){
		int zero = 0,one = 0;
		for(int i = 0;i < n;++i){
			int a;
			cin >> a;
			if(a) one++;
			else zero++;
		}
		cout << "Case " << cnt++ << ": " << one - zero << "\n";
	}

	return 0;
}