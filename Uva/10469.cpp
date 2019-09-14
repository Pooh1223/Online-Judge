#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a,b;

	while(cin >> a >> b){
		string bia = bitset<32>(a).to_string(),bib = bitset<32>(b).to_string();
		
		reverse(bia.begin(),bia.end());
		reverse(bib.begin(),bib.end());

		string ans = "";

		for(int i = 0;i < 32;++i){
			int na = bia[i] - '0',nb = bib[i] - '0';
			if(na + nb == 2 || na + nb == 0) ans += "0";
			else ans += "1";
		}
		reverse(ans.begin(),ans.end());
		cout << bitset<32>(ans).to_ullong() << "\n";

	}

	return 0;
}