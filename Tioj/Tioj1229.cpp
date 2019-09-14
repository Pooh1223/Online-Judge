#include <iostream>
#include <string>
using namespace std;

int main(){
	int n,len,time;
	cin >> n >> len >> time;
	int num[105];
	for(int i = 0,j;i < len;i++) {
		cin >> j;
		num[i] = j - 1;
	}
	while(n--){
		string sen;
		cin >> sen;
		char ans[105];
		int senlen = sen.length();
		for(int j = 0;j < time;j++){
			for(int i = 0;i < len;i++) ans[num[i]] = sen[i];
			for(int i = 0;i < len;i++) sen[i] = ans[i];
		}
		for(int i = 0;i < len;i++) cout << ans[i];
		cout << "\n";
	}
	return 0;
}
