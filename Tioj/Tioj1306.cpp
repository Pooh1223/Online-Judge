#include <bits/stdc++.h>
using namespace std;
int f[10005];
string s1,s2;
int kmp(const string &A,const string &B){
	if(B.length() > A.length()) return 0;
	memset(f,0,sizeof(f));
	int cnt = 0;
	f[0] = -1,f[1] = 0;
	for(int i = 1,j = 0;i < (int)B.size() - 1;f[++i] = ++j){
		if(B[i] == B[j]) f[i] = f[j];
		while(j != -1 && B[i] != B[j]) j = f[j];
	}
	//for(int i = 0;i <= (int)B.size();++i) cout << i << " : " << f[i] << "\n";
	//cout << "\n";
	for(int i = 0,j = 0;i - j + (int)B.size() <= (int)A.size();++i,++j){
		while(j != -1 && A[i] != B[j]) j = f[j];
		if(j == B.size() - 1){
			cnt++;
			j = f[j];
		}
	}
	return cnt;
}
int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> s1;
		int n;
		cin >> n;
		while(n--){
			cin >> s2;
			cout << kmp(s1,s2) << "\n";
		}
	}
	return 0;
}