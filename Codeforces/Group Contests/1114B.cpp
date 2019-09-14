#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll,ll> mp;
ll num[200005],ogn[200005],sum;

bool cmp(ll a, ll b){
	return a > b;
}

void printmap(){
	cout << "map : \n";
	map<ll,ll>::iterator iter;
	for(iter = mp.begin();iter != mp.end();++iter){
		cout << iter -> first << " " << iter -> second << "\n";
	}
	cout << "end\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1;i <= n;++i){
		cin >> num[i];
		ogn[i] = num[i];
	} 
	sort(num + 1,num + n + 1,cmp);
	map<ll,ll>::iterator iter;
	for(int i = 1;i <= m * k;++i){
		iter = mp.find(num[i]);
		mp[num[i]]++;
		sum += num[i];
	}
	cout << sum << "\n";
	int cnt = 0,fin = 0;
	for(int i = 1;i <= n;++i){
		iter = mp.find(ogn[i]);
		if(cnt < m && iter != mp.end()){ // exist in sum and it should --
			cnt++;
			if(mp[iter -> first] == 1) mp.erase(iter);
			else mp[iter -> first]--;
		} 
		if(fin == k - 1){
			break;
		} else if(cnt == m){
			cout << i << " ";
			cnt = 0;
			fin++;
		}
		//printmap();
	}

	return 0;
}