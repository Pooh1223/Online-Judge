#include <bits/stdc++.h>
using namespace std;
bool prob[10005];
vector<int> v[10005];
bool find(int n){
	if(prob[n] == 1) return 1;
		for(int i = 0;i < v[n].size();++i){
            if(find(v[n][i])) return 1;
            else return 0;
        }
}
int main(){
	cin.tie(0);
	int n,m,l,q;
	cin >> n >> m >> l >> q;
	while(m--){
		int a,b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	while(l--){
		int a;
		cin >> a;
		prob[a] = 1;
	}
	while(q--){
		int a;
		cin >> a;
		if(find(a)) cout << "TUIHUOOOOOO\n",prob[a] = 1;
		else cout << "YA~~\n";
	}
	return 0;
}