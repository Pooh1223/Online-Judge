#include <bits/stdc++.h>
using namespace std;

int d[130];
bool used[10005];

int main(){

	int n,mx = 0;
	cin >> n;

	for(int i = 0;i < n;++i){
		cin >> d[i];
		mx = max(mx,d[i]);
	} 

	cout << mx << " ";

	for(int i = 0;i < n;++i){
		if(mx % d[i] == 0 && !used[d[i]]){
			used[d[i]] = 1;
			d[i] = 0;
		}
	}

 	mx = 0;

	for(int i = 0;i < n;++i){
		mx = max(d[i],mx);	 
	}

	cout << mx;

	return 0;
}