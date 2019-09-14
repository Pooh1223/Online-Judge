#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		vector<int> v;
		int wn = 0,ls = 0;
		for(int i = 0;i < n;++i){
			int j;
			cin >> j;
			if(j > 0) wn++;
			else ls++;
			v.push_back(abs(j));
		}
		sort(v.begin(),v.end());
		double sum = 0.0;
		for(int i = 1;i < (int)v.size() - 1;++i) sum += (double)v[i];
		printf("Average time: %.3f sec(s).\n",sum / (double)(v.size() - 2));
		printf("Winning rate: %.3f %%.\n",(double)((double)wn * 100.0 / (double)(wn + ls)));
	}
	return 0;
}