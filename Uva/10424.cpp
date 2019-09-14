#include <bits/stdc++.h>
using namespace std;

int main(){

	string a,b;
	while(getline(cin,a,'\n')){
		getline(cin,b,'\n');
		int suma = 0,sumb = 0;

		for(int i = 0;i < a.length();++i){
			if(a[i] - 'A' >= 0 && a[i] - 'A' <= 25){
				suma += a[i] - 'A' + 1;
			} else if(a[i] - 'a' >= 0 && a[i] - 'a' <= 25){
				suma += a[i] - 'a' + 1;
			}
		}
		for(int i = 0;i < b.length();++i){
			if(b[i] - 'A' >= 0 && b[i] - 'A' <= 25){
				sumb += b[i] - 'A' + 1;
			} else if(b[i] - 'a' >= 0 && b[i] - 'a' <= 25){
				sumb += b[i] - 'a' + 1;
			}
		}
		int num = 0;
		while(1){
			while(suma){
				num += suma % 10;
				suma /= 10;
			}
			suma = num;
			num = 0;
			if(suma < 10) break; 
		}
		num = 0;
		while(1){
			while(sumb){
				num += sumb % 10;
				sumb /= 10;
			}
			sumb = num;
			num = 0;
			if(sumb < 10) break; 
		}
		if(suma < sumb) swap(suma,sumb);
		printf("%.2f %\n",(double)sumb / (double)suma * 100.0);
	}

	return 0;
}