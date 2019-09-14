#include <bits/stdc++.h>
using namespace std;
map<string,vector<string> > pos1;
map<int,string> pos2;
vector<pair <string,int> > v[1003];
int main(){
	int n;
	cin >> n;
	int a = 0,b = 0;
	while(n--){
		string am,pos;
		int cnt;
		cin >> am >> cnt >> pos;
		bool ck1 = 0,ck2 = 0;
		if(pos1.find(pos) == pos1.end()){
			pos1.insert(make_pair(pos,a++));
			ck1 = 1;
		}
		if(amm.find(am) == amm.end()){
			amm.insert(make_pair(am,b++));
			ck2 = 1;
		}
		v[ck1 ? a - 1 : pos1[pos]].push_back(make_pair(ck2 ? b - 1 : amm[am],cnt));
	}

	return 0;
}