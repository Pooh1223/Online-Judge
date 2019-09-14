#include <bits/stdc++.h>
using namespace std;

int len[1003][1003];

int main(){

	string a,b;

	while(getline(cin,a,'\n')){
		getline(cin,b,'\n');
		for(int i = 0;i < 1003;++i){
			len[i][0] = 0;
			len[0][i] = 0;
		}
		for(int i = 0;i < a.length();++i){
			for(int j = 0;j < b.length();++j){
				if(a[i] == b[j]){
					if(!i || !j) len[i][j] += 1;
					else len[i][j] = len[i - 1][j - 1] + 1;
				} else {
					if(!i) len[i][j] = len[i][j - 1];
					else if(!j) len[i][j] = len[i - 1][j];
					else len[i][j] = max(len[i][j - 1],len[i - 1][j]);
				}
			}
		}
		cout << len[a.length() - 1][b.length() - 1] << "\n";
	}

	return 0;
}