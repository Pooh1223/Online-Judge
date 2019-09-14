#include <iostream>
//#include <cstring>
using namespace std;

int main(){
	int g,alpha[26],num[26],q = 1;
	char w[g];
	cin >> g;
	memset(alpha,0,sizeof(alpha));
	for(int i = 0;i < g;i++){
		cin >> w[i];
		cout << (int)w[i] - 97 << endl;
		alpha[(int)w[i] - 97] = alpha[(int)w[i] - 97] + 1;
	}
	cout << alpha[0] << endl;
	g = alpha[0];
	cout << g << endl;
	for(int j = 1;j < 26;j++){
		if(alpha[j] > g){
			g = alpha[j];
			num[0] = j;
		} 
	}
	for(int k = num[0];k < 26;k++){
		if(alpha[k] == g){
			num[q] = k;
			q++;
		}
	}
	for(int l = 0;l <= q;l++){
		cout << (char)(num[l] + 97);
		if(l == q) cout << endl;
	}
	return 0;
}
