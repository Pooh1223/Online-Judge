#include <iostream>
#include <vector>
using namespace std;
vector<int> gragh[10005];
bool used[10005];
int cnt = 0;
void dfs(int n){
	bool ck = 0;
	for(int i = 0;i < gragh[n].size();i++){
		if(!used[i]){
			used[i] = 1;
			dfs(gragh[n][i]);
			used[i] = 0;
			ck = 1;
		} 
	}
	if(ck) cnt++;
}
int main(){
	int p,m;
	cin >> p >> m;
	while(m--){
		int a,b;
		cin >> a >> b;
		gragh[a].push_back(a);
		gragh[b].push_back(b);
	}
	used[0] = 1;
	cout << cnt << "\n";
	return 0;
}