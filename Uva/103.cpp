#include <bits/stdc++.h>
using namespace std;

int len[33];
int pre[33];
int n,m;

struct nm{
	int id;
	int sz[13];
	bool operator<(const nm &a)const{
		for(int i = 0;i < m;++i){
			if(a.sz[i] != sz[i]) return a.sz[i] < sz[i];
		}
	}
}box[33];

bool smaller(int a,int b){
	for(int i = 0;i < m;++i){
		if(box[a].sz[i] <= box[b].sz[i]) return 0;
	}
	return 1;
}

int main(){
	
	while(cin >> n >> m){
		fill(len,len + 33,1);
		fill(pre,pre + 33,-1);

		for(int i = 0;i < n;++i){
			for(int j = 0;j < m;++j){
				cin >> box[i].sz[j];
			}
			box[i].id = i;
			sort(box[i].sz,box[i].sz + m);
		}
		sort(box,box + n);

		// for(int i = 0;i < n;++i){
		// 	for(int j = 0;j < m;++j){
		// 		cout << box[i].sz[j] << " ";
		// 	}
		// 	cout << "\n";
		// }

		for(int i = 0;i < n;++i){
			for(int j = i + 1;j < n;++j){
				if(smaller(i,j)){
					if(len[i] + 1 > len[j]){
						len[j] = len[i] + 1;
						pre[j] = i;
					}
				}
			}
		}

		int mx = -1,id = -1;
		for(int i = 0;i < n;++i){
			if(mx < len[i]){
				mx = len[i];
				id = i;
			}
		}

		cout << mx << "\n" << box[id].id + 1;
		while(pre[id] != -1){
			cout << " " << box[pre[id]].id + 1;
			id = pre[id];
		}
		cout << "\n";
	}
	return 0;
}