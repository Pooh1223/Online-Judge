#include <bits/stdc++.h>
using namespace std;

bool order(int a,int b,int c,int d){
	return (a < b) && (b < c) && (c < d);
}

int main(){
	string s;
	cin >> s;
	int st = -1,stCo = -1,edCo = -1,ed = -1;
	bool first = 0;
	int cnt = 0;
	for(int i = 0;i < s.length();++i){
		if(!first && s[i] == '['){
			st = i;
			first = 1;
		} else if(first && s[i] == ':'){
			stCo = i;
			break;
		}
	}
	first = 0;
	for(int i = s.length() - 1;i >= 0;--i){
		if(!first && s[i] == ']'){
			first = 1;
			ed = i;
		} else if(first && s[i] == ':'){
			edCo = i;
			break;
		}
	}
	if(st == -1 || stCo == -1 || ed == -1 || edCo == -1) cout << -1 << "\n";
	else if(stCo == edCo) cout << -1 << "\n";
	else if(!order(st,stCo,edCo,ed)) cout << -1 << "\n";
	else {
		int cnt = 4;
		for(int i = stCo + 1;i < edCo;++i) if(s[i] == '|') cnt++;
		cout << cnt << "\n";
	}
	
	return 0;
}