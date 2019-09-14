#include <bits/stdc++.h>
using namespace std;

struct tree{
	long long sum,val;
}node[100005];

int pre[100005];
vector<int> v[100005];
bool fail = 0;

long long dfs(int u){
	long long ans = 0;
	for(int i = 0;i < v[u].size();++i){
		ans += dfs(v[u][i]);
	}
	if(fail) return -1;
	if(node[u].sum == -1){
		if(!v[u].size()){
			node[u].val = 0;
			node[u].sum = node[pre[u]].sum;
		} else {
			long long mn = 1e18;
			for(int i = 0;i < v[u].size();++i){
				mn = min(mn,node[v[u][i]].sum);
				if(node[v[u][i]].sum < node[pre[u]].sum){
					fail = 1;
					return -1;
				}
			}
			node[u].val = mn - node[pre[u]].sum;
			node[u].sum = mn;
			for(int i = 0;i < v[u].size();++i){
				node[v[u][i]].val = node[v[u][i]].sum - node[u].sum;
				ans += node[v[u][i]].val;
			}
		}
	} else {
		if(!v[u].size()){
			long long jizz = node[pre[u]].sum == -1 ? node[pre[pre[u]]].sum : node[pre[u]].sum;
			//cout << "u : " << u << " jizz : " << jizz << " now sum : " << node[u].sum << "\n";
			if(node[u].sum < jizz){
				//cout << "jizz!!!\n";
				fail = 1;
				return -1;
			} 
			if(node[pre[u]].sum != -1) node[u].val = node[u].sum;
		} else if(u != 1){
			if(node[pre[u]].sum != -1){
				if(node[u].sum < node[pre[u]].sum){
					fail = 1;
					return -1;
				} 
				node[u].val = node[u].sum - node[pre[u]].sum;
			}
		}
	}
	ans += node[u].val;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	pre[1] = 1;
	for(int i = 0;i < n - 1;++i){
		int jizz;
		cin >> jizz;
		v[jizz].push_back(i + 2);
		pre[i + 2] = jizz;
	}

	for(int i = 1;i <= n;++i){
		int jizz;
		cin >> jizz;
		node[i].sum = jizz;
		node[i].val = 0;
	}
	node[1].val = node[1].sum;

	cout << dfs(1);

	return 0;
}