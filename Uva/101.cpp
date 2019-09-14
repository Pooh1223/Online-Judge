#include <bits/stdc++.h>
using namespace std;

vector<int> v[30];
int pos[30];

int main(){

	int n;
	cin >> n;
	string s;
	for(int i = 0;i < n;++i){
		pos[i] = i;
		v[i].push_back(i);
	} 
	while(getchar() != '\n');

	while(getline(cin,s)){
		if(s == "quit"){
			for(int i = 0;i < n;++i){
				cout << i << ":";
				for(int j = 0;j < v[i].size();++j){
					cout << " " << v[i][j];
				}
				cout << "\n";
			}
			break;
		}

		int a,b;
		bool st = 1;
		string num;
		for(int i = 5;i < s.length();++i){
			if(s[i] == ' ' && st){
				a = stoi(num);
				num = "";
				st = 0;
				continue;
			}
			if(s[i] - '0' >= 0 && s[i] - '0' <= 9) num += s[i];
		}
		b = stoi(num);
		if(pos[a] == pos[b]) continue;

		if(s[0] == 'm'){
			for(int i = v[pos[a]].size() - 1;v[pos[a]][i] != a;--i){
				v[v[pos[a]][i]].push_back(v[pos[a]][i]);
				pos[v[pos[a]][i]] = v[pos[a]][i];
				v[pos[a]].pop_back();
			}
			if(s[8] == 'n' || s[9] == 'n'){
				for(int i = v[pos[b]].size() - 1;v[pos[b]][i] != b;--i){
					v[v[pos[b]][i]].push_back(v[pos[b]][i]);
					pos[v[pos[b]][i]] = v[pos[b]][i];
					v[pos[b]].pop_back();
				}
			} 
			v[pos[b]].push_back(a);
			v[pos[a]].pop_back();
			pos[a] = pos[b];
		} else {
			bool pass = 0;
			int apos = pos[a];
			if(s[8] == 'n' || s[9] == 'n'){
				for(int i = v[pos[b]].size() - 1;v[pos[b]][i] != b;--i){
					v[v[pos[b]][i]].push_back(v[pos[b]][i]);
					pos[v[pos[b]][i]] = v[pos[b]][i];
					v[pos[b]].pop_back();
				}
			}
			for(int i = 0;i < v[apos].size();++i){
				if(v[apos][i] == a) pass = 1;
				if(pass){
					v[pos[b]].push_back(v[apos][i]);
					pos[v[apos][i]] = pos[b];
				}
			}

			while(v[apos].back() != a) v[apos].pop_back();
			v[apos].pop_back();
		}
		
	}

	
	return 0;
}