#include <bits/stdc++.h>
using namespace std;

vector<int> v[30];
bool used[30];

void dfs(int u){
	for(int i = 0;i < v[u].size();++i){
		if(!used[v[u][i]]){
			used[v[u][i]] = 1;
			dfs(v[u][i]);
		}
	}
}

int main(){
	int t;
	cin >> t;
	for(int k = 0;k < t;++k){
		for(int i = 0;i < 30;++i) v[i].clear();
		memset(used,0,sizeof(used));
		
		if(k) cout << "\n";
		char c;
		if(!k){
			getchar();
			getchar();
		} 
		c = getchar();

		int n = c - 'A' + 1;
		// cout << "c : " << (int)c << "\n";
		// cout << n << "\n";

		string s;
		while(getchar() != '\n');
		while(getline(cin,s)){
			if(s == "\n" || !s.length()) break;
			v[s[0] - 'A'].push_back(s[1] - 'A');
			v[s[1] - 'A'].push_back(s[0] - 'A');
		}
		
		int cnt = 0;
		for(int i = 0;i < n;++i){
			if(!used[i]){
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}