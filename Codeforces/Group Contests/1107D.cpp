#include <bits/stdc++.h>
using namespace std;

bool mp[5203][5203];
int pre[5203][5203];
string s[] = {"0000","0001","0010","0011",
			  "0100","0101","0110","0111",
			  "1000","1001","1010","1011",
			  "1100","1101","1110","1111"};

int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;++i){
		string str = "";
		cin >> str;
		for(int j = 0;j < n / 4;++j){
			int present;
			if(str[j] - '0' > 9){
				present = str[j] - '7';
			} else {
				present = str[j] - '0';
			}
			for(int k = 0;k < 4;++k){
				mp[j * 4 + k][i] = s[present][k] - '0';
				int up,left,minus;

				if(j * 4 + k - 1 < 0) up = 0;
				else up = pre[j * 4 + k - 1][i];

				if(i - 1 < 0) left = 0;
				else left = pre[j * 4 + k][i - 1];

				if(j * 4 + k - 1 < 0 || i - 1 < 0) minus = 0;
				else minus = pre[j * 4 + k - 1][i - 1];

				pre[j * 4 + k][i] += up + left + (s[present][k] - '0') - minus;
			}
		}		
	}

	int sz;

	for(sz = n;sz > 1;--sz){
		if(n % sz) continue;
		bool ck = 1;
		for(int i = sz - 1;i < n;i += sz){
			for(int j = sz - 1;j < n;j += sz){
				int up,left,add;

				if(i - sz < 0) up = 0;
				else up = pre[i - sz][j];

				if(j - sz < 0) left = 0;
				else left = pre[i][j - sz];

				if(i - sz < 0 || j - sz < 0) add = 0;
				else add = pre[i - sz][j - sz];

				//cout << i << " " << j << "  : " << pre[i][j] - up - left + add << "\n";

				if(pre[i][j] - up - left + add != sz * sz && pre[i][j] - up - left + add != 0){
					ck = 0;
					break;
				}
			}
			if(!ck) break;
		}

		if(ck) break;
	}

	cout << sz << "\n";

	// for(int i = 0;i < n;++i){
	// 	for(int j = 0;j < n;++j){
	// 		cout << mp[i][j];
	// 	}
	// 	cout << "\n";
	// }

	// for(int i = 0;i < n;++i){
	// 	for(int j = 0;j < n;++j){
	// 		cout << pre[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	return 0;
}