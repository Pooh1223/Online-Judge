#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a;
	getline(cin,a);
	int len = a.length(),mx = -1,mn = 100005;
	for(int i = 0;i < len;i++){
		a[i] = (int)a[i];
		if(a[i] > mx) mx = a[i];
		if(a[i] < mn) mn = a[i];
	}
	for(int i = mn;i <= mx;i++){
		for(int j = 0;j < len;j++){
			if(a[j] == i) cout << j << " \n";
		}
	}
	return 0;
}
