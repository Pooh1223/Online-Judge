#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
int num[101][101];

int main(){
	prime.push_back(2);
	for(int i = 3;i < 100;++i){
		bool ck = 0;
		for(int j = 2;j < i;++j){
			if(!(i % j)){
				ck = 1;
				break;
			}
		}
		if(!ck) prime.push_back(i);
	}

	for(int i = 2;i <= 100;++i){
		int n = i;
		int pos = 0;
		for(int j = 0;j < 101;++j) num[i][j] = num[i - 1][j];
		while(n != 1){
			
			if(!(n % prime[pos])){
				n /= prime[pos];
				num[i][prime[pos]]++;
			} else if(pos + 1 < prime.size()){
				pos++;
			}
		}
	}

	int t;
	while(cin >> t && t){
		int cnt = 0;
		printf("%3d! =",t);
		bool ck = 0;
		for(int i = 0;i < 101;++i){
			if(cnt == 15 && !ck){
				ck = 1;
				if(prime[15] <= t) printf("\n      ");
			}
			if(num[t][i]){
				printf("%3d",num[t][i]);
				cnt++;
			}
		}

		cout << "\n";
	}

	return 0;
}