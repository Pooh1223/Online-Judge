#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		for(int i = 1;i < n;++i){

			int s = 0;
			for(int j = 2;j < n;++j)
				s = (s + i) % j;

			if(s == 11){
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}