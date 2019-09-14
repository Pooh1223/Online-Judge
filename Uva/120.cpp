#include <bits/stdc++.h>
using namespace std;

int num[103];

int main(){

	string s;
	while(getline(cin,s)){
		s += ' ';
		string ss = "";
		int len = 0;
		for(int i = 0;i < s.length();++i){
			if(s[i] != ' ') ss += s[i];
			else{
				num[len++] = stoi(ss);
				ss = "";
			} 
		}

		for(int i = 0,j = len - 1;j - i >= 1;++i,--j){
			swap(num[i],num[j]);
		}

		cout << s << "\n";
		//for(int i = 0;i < len;++i) cout << num[i] << " ";
		//cout << "\n";

		int cnt = 0;

		while(1){
			int mx = -1;
			int pos = -1;
			for(int i = cnt;i < len;++i){
				if(mx < num[i]){
					mx = num[i];
					pos = i;
				}
			}

			if(pos == cnt);
			else if(pos == len - 1){
				cout << cnt + 1 << " ";
				for(int i = cnt,j = len - 1;j - i >= 1;++i,--j){
					swap(num[i],num[j]);
				}
			} else {
				cout << pos + 1 << " " << cnt + 1 << " ";
				for(int i = pos,j = len - 1;j - i >= 1;++i,--j){
					swap(num[i],num[j]);
				}
				for(int i = cnt,j = len - 1;j - i >= 1;++i,--j){
					swap(num[i],num[j]);
				}
			}

			bool end = 1;
			for(int i = 1;i < len;++i){
				if(num[i - 1] < num[i]){
					end = 0;
					break;
				}
			}
			if(end){
				cout << "0\n";
				break;
			}
			cnt++;
		}
	}

	return 0;
}