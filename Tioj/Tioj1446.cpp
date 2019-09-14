#include <bits/stdc++.h>
using namespace std;
string s[100005];
int cmp(string a,string b){
	return a.compare(b) < 0;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0;i < n;++i){
		cin >> s[i];
	}
	sort(s,s + n,cmp);
	int cnt = 0;
	for(int i = 0;i < n;++i){
		if(i == 0) cnt += (int)s[i].size() + 1;
		else {
			int j = 0;
			for(;j < min(s[i].size(),s[i - 1].size());++j){
				if(s[i][j] != s[i - 1][j]) break;
			}
			cnt += (int)s[i - 1].size() - j + (int)s[i].size() - j + 1;
		}
	}
	cnt += s[n - 1].size();
	cout << cnt << "\n";
	return 0;
}