#include <bits/stdc++.h>
using namespace std;

map<string,int> m;
int nm[6];

int main(){
	
	int cnt = 1;

	while(cnt <= 83681){
		
		int pos = 0;
		bool carry = 0;

		nm[pos]++;

		while(nm[pos] + carry == 27 - pos){
			nm[pos]= 1;
			pos++;
			carry = 1;
		}

		if(carry){
			nm[pos]++;
			while(--pos){
				nm[pos] = nm[pos + 1] + 1;
			}
			nm[pos] = nm[pos + 1] + 1;
		}

		string ss = "";
		for(int i = 5;i >= 0;--i){
			if(nm[i]) ss += char(nm[i] - 1 + 'a');
		}
		
		m[ss] = cnt;
		cnt++;
	}

	string s;
	while(cin >> s){
		if(m.find(s) == m.end()){
			cout << "0\n";
		} else {
			cout << m[s] << "\n";
		}
	}
	
	return 0;
}