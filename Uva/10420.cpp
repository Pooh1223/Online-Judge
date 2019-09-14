#include <bits/stdc++.h>
using namespace std;
int num[200];

int main(){
	int t;
	cin >> t;
	string s,c[200];
	for(int i = 0;i < 200;++i) c[i] = "";
	while(getchar() != '\n');
	
	int pos = 0;

	while(t--){
		bool exist = 0;
		
		getline(cin,s,'\n');

		string a = "";
		int k = 0;
		while(s[k] == ' ') ++k;

		for(;k < s.length();++k){
			if(s[k] == ' ') break;
			a += s[k];	
		}

		for(int i = 0;i < pos;++i){
			if(c[i] == a){
				num[i]++;
				exist = 1;
				break;
			}
		}
		if(!exist){
			c[pos] = a;	
			num[pos++]++;
		} 
	}
	for(int i = 0;;++i){
		if(!num[i]){
			sort(c,c + i);
			for(int j = 0;j < i;++j){
				cout << c[j];
			}
			break;
		}
		else c[i] += " " + to_string(num[i]) + "\n";
	}
	return 0;
}