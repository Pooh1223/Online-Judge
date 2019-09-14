#include <bits/stdc++.h>
using namespace std;

map<string,int,less<string> > mp;

int main(){
	int t;
	cin >> t;
	while(getchar() != '\n');
	getchar();
	for(int k = 0;k < t;++k){
		mp.clear();
		if(k) printf("\n");
		int cnt = 0;
		string s;
		while(getline(cin,s)){
			if(!s.length()) break;
			if(mp.find(s) != mp.end()) mp[s]++;
			else mp[s] = 1;
			cnt++;
		}
		map<string,int>::iterator iter;
		for(iter = mp.begin();iter != mp.end();++iter){
			cout << iter->first << " ";
			printf("%.4f\n",100.0 * (float)iter->second / (float)cnt);
		}
	}

	return 0;
}