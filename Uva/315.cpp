#include <bits/stdc++.h>
using namespace std;

bool used[103];
vector<int> v[103];
vector<int> cri[103];
set<int> st;

void dfs(int u){
	for(int i = 0;i < v[u].size();++i){
		if(!used[v[u][i]]){
			used[v[u][i]] = 1;
			dfs(v[u][i]);
		}
	}
}

int main(){

	int n;
	while(cin >> n && n){
		for(int i = 0;i < 103;++i){
			v[i].clear();
			cri[i].clear();
		} 
		st.clear();

		int m;
		while(cin >> m && m){

			string s;
			getline(cin,s);

			stringstream ss;
			ss << s;

			while(1){
				int k;
				ss >> k;
				if(ss.fail()) break;

				v[m].push_back(k);
				v[k].push_back(m);

				cri[m].push_back(k);
			}
		}

		for(int i = 1;i <= n;++i){
			memset(used,0,sizeof(used));
			used[i] = 1;
			
			if(i + 1 <= n) dfs(i + 1);
			else dfs(1);

			for(int j = 1;j <= n;++j){
				if(!used[j]){
					//it's ap
					
					st.insert(i);
					break;
				}
			}
		}
		if(n != 2) cout << st.size() << "\n";
		else cout << "0\n";
		
	}
	return 0;
}