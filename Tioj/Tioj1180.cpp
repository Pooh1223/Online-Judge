#include <iostream>
#include <cstring>
using namespace std;
int by(int);
int word(int);
int main(){
	int n,a[n];
	while(cin >> n){
		for(int i = 0;i <= n;i++){
			cin >> a[i];
			cout << word(a[i]) << endl;
		}
	}
	return 0;
} 
//»¼°j 
int by(int i){
	int a[14];
	memset(a , 0 , sizeof(a));
	if (a[i]) return a[i];
	else if (i == 1) return a[i] = 1;
	else return a[i] = i * (i - 1);
}
//x case ­Ó¼Æ,y ¶¥­¼¼Æ 
int word(int x,int y){
	for(int i = 1;i <= x;i++){
		cout << "Case #" << i << ":" << endl;
		for(int j = 0;j <= i; j++)
		cout << "TFCIS";
	}
}
