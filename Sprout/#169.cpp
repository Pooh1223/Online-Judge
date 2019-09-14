#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int> > g[1050];
vector<int> k; 
vector<int> ans;
int cnt[1050];
bool used[1050];
struct node{
	int a,b;
}t[1050];
bool cmp1(node ji,node zz){return ji.a < zz.a;}
bool cmp2(node ji,node zz){return ji.b < zz.b;}
void dfs(int n){
	int v,id;
	for(int i = 0;i < g[n].size();++i){
		v = g[n][i].first;
		id = g[n][i].second;
		if(!used[id] && cnt[n] > 0){
			cnt[n]--;
			cnt[v]--;
			used[id] = 1;
			k.push_back(v);
			dfs(v);
		}
	}
	/*if(cnt[n] == 0) */ans.push_back(k.back());k.pop_back();
}
int main(){
	cin.tie(0);
	int n;
	cin >> n;
	int even = 10000;
	for(int i = 0;i < n;++i){
		cin >> t[i].a >> t[i].b;
		if(t[i].a > t[i].b) swap(t[i].a,t[i].b);
		//t[i].a = x,t[i].b = y;
	}
	sort(t,t + n,cmp2);
	sort(t,t + n,cmp1);
	for(int i = 0;i < n;++i){
		g[t[i].a].push_back(make_pair(t[i].b,i));
		g[t[i].b].push_back(make_pair(t[i].a,i));
		even = min(even,min(t[i].a,t[i].b));
	}
	int odd1 = -1,odd2 = -1;
	for(int i = 1;i < 1050;++i){
		if(g[i].size() > 0){
			cnt[i] = g[i].size();
			if(cnt[i] % 2 && odd1 == -1) odd1 = i;
			else if(cnt[i] % 2 && odd1 != -1) odd2 = i;
		}
	}
	if(odd1 != -1){
		//cout << "odd1 : " << odd1 << " odd2 : " << odd2 << "\n"; 
		k.push_back(odd1);
		dfs(odd1);
	} 
	else{
		//cout << "even : " << even << "\n";
		k.push_back(even);
		dfs(even);
	} 
	while(ans.size() > 0){
		cout << ans.back() << "\n";
		ans.pop_back();
	}
	return 0;
}