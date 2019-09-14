#include <bits/stdc++.h>
using namespace std;

bool cmp(int &a,int &b){
	return a > b;
}

int n,lmt,dmg[200005];

int main(){
	
	long long sum = 0;
	string s;

	cin >> n >> lmt;
	for(int i = 0;i < n;++i) cin >> dmg[i];
	cin >> s;

	s += '.';
	
	int cnt = 1;
	long long ssum = dmg[0];
	vector<int> v;
	v.push_back(dmg[0]);

	for(int i = 1;i <= n;++i){
		
		if(s[i] == s[i - 1]){
			cnt++;
		} else {
			if(cnt > lmt){
				ssum = 0;
				sort(v.begin(),v.end(),cmp);
				for(int j = 0;j < lmt;++j) sum += v[j];
			} else {
				sum += ssum;
				ssum = 0;
			}
			v.clear();
			cnt = 1;
		}

		ssum += dmg[i];
		v.push_back(dmg[i]);
	}

	cout << sum;

	return 0;
}