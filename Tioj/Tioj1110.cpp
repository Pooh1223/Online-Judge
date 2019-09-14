#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int s;
	cin >> s;
	while(s--){
		int g,alpha[30],max = 0;
		char w;
		memset(alpha,0,sizeof(alpha));
		cin >> g;
		for(int i = 0;i < g;i++){
			cin >> w;
			alpha[w - 'a']++;
			if(alpha[w - 'a'] > max) max = alpha[w - 'a'];
		}
		for(int j = 0;j < 26;j++){
			if(alpha[j] == max){
				cout << (char)(j + 'a');
			}
		}
		cout << endl;
	}
	return 0;
} 
