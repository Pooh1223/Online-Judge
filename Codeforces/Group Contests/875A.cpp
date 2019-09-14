#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
	int n,k = 0;
	cin >> n;
	for(int i = n - 100 > 1 ? n - 100 : 1,sum;i < n;++i){
		sum = 0;
		int j = i;
		sum += j;
		while(j > 9){
			sum += j % 10;
			j /= 10;
			//if(i == 10000000) cout << sum << "\n";
		}
		//cout << i << " " << j << "\n";
		sum += j;
		
		//if(sum > n) break;
		if(sum == n) ++k,v.push_back(i);
		
	}
	cout << k << "\n";
	int q = 10000001,w = 10000001;
	for(int i = 0;i < v.size();++i) cout << v[i] << "\n";
	return 0;
}