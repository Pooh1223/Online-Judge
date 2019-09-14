#include <bits/stdc++.h>
using namespace std;
struct t{
	int min,id;
	bool operator<(const t&a)const{
		return min < a.min;
	}
}sub[50];
int main(){
	int n,k,m;
	cin >> n >> k >> m;
	int sum = 0;
	for(int i = 0;i < k;++i){
		cin >> sub[i].min;
		sum += sub[i].min;
		sub[i].id = i;
	}
	sort(sub,sub + k);
	int mx = -1;
	for(int i = 0;i <= n;++i){
		int now = m - i * sum;
		if(now < 0) break;
		int q = n - i;
		int pt = i * (k + 1);
		bool b = 1;
		for(int j = 0;j < k && b;++j){
			for(int l = 0;l < q && b;++l){
				if(now - sub[j].min >= 0){
					now -= sub[j].min;
					pt++;
					if(j == k - 1) pt++;
				}
				else b = 0;
			}
		}
		//cout << i << " : " << pt << "\n";
		mx = max(mx,pt);
	}
	cout << mx << "\n";
	return 0;
}