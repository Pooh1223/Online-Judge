#include <bits/stdc++.h>
using namespace std;
int num[105],sum[105];
int n;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){	
		scanf("%d",&n);
		int m;
		for(int i = 0;i < n;++i){
			scanf("%d",&num[i]);
			m += num[i];
			sum[i] = m;
		}
		int ans = m / 2;
		int mid = n / 2;
		while(sum[mid] )
	}
	return 0;
}