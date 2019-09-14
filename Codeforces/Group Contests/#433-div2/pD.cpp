#include <bits/stdc++.h>
using namespace std;
struct flight{
	int d,f,t,c;
}q[100005];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0;i < m;++i){
		cin >> q[i].d >> q[i].f >> q[i].t >> q[i].c;
	}
	
	return 0;
}