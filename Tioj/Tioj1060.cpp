#include <iostream>
#include <cstring>
using namespace std;

int dpf[100000],dph[100000];

int h(int b){
	if(dph[b + 300]) return dph[b + 300];
	if(b < 2) return -1;
	else return dph[b + 300] = 2 + h(b - 1) - h(b - 2);
}

int f(int a){
	if(!dph[a + 300]) dph[a + 300] = h(a);
	if(a > dph[a + 300]){
		if(dpf[a + 300]) return dpf[a + 300];
		else return dpf[a + 300] = f(a - 1) - dph[a + 300];
	} 
	else if(dph[a + 300] > a){
		int ram;
		if(a <= 2) ram = (a * a) - 1;
		else ram = 2;
		if(dpf[a + 300]) return dpf[a + 300];
		else return dpf[a + 300] = f(ram) - ram;
	} 
	else return 1;
}

int main(){
	memset(dpf,0,sizeof(dpf));
	memset(dph,0,sizeof(dph));
	int x;
	while(cin >> x){
		cout << f(x) << endl;
	}
	return 0;
} 

