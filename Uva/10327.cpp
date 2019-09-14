#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		int num[1003];
		for(int i = 0;i < n;++i) cin >> num[i];
		int cnt = 0;

		for(int i = n - 1;i > 0;--i){
			for(int j = 0;j < i;++j){
				if(num[j] > num[j + 1]){
					swap(num[j],num[j + 1]);
					cnt++;
				} 
			}
		}
		cout << "Minimum exchange operations : " << cnt << "\n";
	}

	return 0;
}