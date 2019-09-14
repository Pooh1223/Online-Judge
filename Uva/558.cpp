#include <bits/stdc++.h>
using namespace std;

struct p{
	int a,b,w;
};

vector<p> v;
int d[1003];

int main(){
	int t;
	cin >> t;
	while(t--){
		v.clear();

		int n,m;
		cin >> n >> m;

		for(int i = 0;i < m;++i){
			int a,b,c;
			cin >> a >> b >> c;
			v.push_back({a,b,c});
		}

		for(int i = 0;i < n;++i) d[i] = 1e9;
		d[0] = 0;

		for(int k = 0;k < n - 1;++k){
			for(int i = 0;i < m;++i){
				if(d[v[i].a] != 1e9){
					if(d[v[i].a] + v[i].w < d[v[i].b]){
						d[v[i].b] = d[v[i].a] + v[i].w;
					}
				}
			}
		}

		bool ok = 0;

		for(int i = 0;i < n;++i){
			for(int j = 0;j < n;++j){
				if(d[v[i].a] + v[i].w < d[v[i].b]){
					ok = 1;
					break;
				}
			}
		}
		if(ok) cout << "possible\n";
		else cout << "not possible\n";
	}

	return 0;
}