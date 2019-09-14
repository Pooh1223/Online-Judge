#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int mxh = -1,mxw = -1;
	for(int i = 0;i < n;++i){
		char type;
		int a,b;
		cin >> type >> a >> b;
		if(a > b) swap(a,b);
		if(type == '+'){
			mxh = max(mxh,a);
			mxw = max(mxw,b);
		} else {
			if(a >= mxh && b >= mxw) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}