#include <bits/stdc++.h>
using namespace std;

int numa[300],numb[300],ans[600];

int main(){
	string a,b;

	while(cin >> a >> b){
		memset(numa,0,sizeof(numa));
		memset(numb,0,sizeof(numb));
		memset(ans,0,sizeof(ans));
		int lena = a.length(),lenb = b.length();
		if(a == "0" || b == "0"){
			cout << "0\n";
			continue;
		}
		if(lena < lenb){
			swap(a,b);
			swap(lena,lenb);
		} 
		
		for(int i = lena - 1;i >= 0;--i)
			numa[lena - 1 - i] = a[i] - '0';
		for(int i = lenb - 1;i >= 0;--i)
			numb[lenb - 1 - i] = b[i] - '0';

		for(int i = 0;i < lenb;++i){
			for(int j = 0;j < lena;++j){
				ans[i + j] += numa[j] * numb[i];
			}
		}

		int carry = 0;
		for(int i = 0;i < lena + lenb;++i){
			int num = ans[i];
			ans[i] = (ans[i] + carry) % 10;
			carry = (num + carry) / 10;
		}
		int pos = lena + lenb;
		while(!ans[pos]) pos--;
		for(;pos >= 0;--pos){
			cout << ans[pos];
		}
		cout << "\n";
	}

	return 0;
}