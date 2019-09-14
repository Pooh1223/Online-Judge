#include <iostream>
#include <string>
using namespace std;

int main(){
	int k;
	string s;
	while(cin >> k >> s){
		char ram[k];
		int len = s.length(),cnt = 0;
		for(int i = 0,j = i;i < len;){
			for(;j < k;j++){
				ram[j] = s[j];	
			}
			bool ck = 1;
			for(int q1 = 0,q2 = j;q1 < k && q2 < len;q1++,q2++){
				if(ram[q1] != s[q2]) ck = 0;
				if (!ck) break;
				else if(q1 == k - 1 && ck) cnt++;
			}
			if(ck) i++;
			else i = j + 
			
		}
	}
	
	return 0;
}
