#include <bits/stdc++.h>
using namespace std;

int pos[10003];
int num[10];

int main(){
	string s = "";
	for(int i = 1;i <= 10000;++i){
		s += to_string(i);
		pos[i] = s.length();
	}

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		memset(num,0,sizeof(num));

		for(int i = 0;i < pos[n];++i){
			num[s[i] - '0']++;
		}
		for(int i = 0;i < 10;++i){
			if(i) cout << " ";
			cout << num[i];
		} 
		cout << "\n";
	}

	return 0;
}