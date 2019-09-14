#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,r_o,o_e,e_r,sum = 0;
	cin >> n >> r_o >> e_r >> o_e;
	char now = 'r';
	n--;
	while(n--){
		if(now == 'r'){
			if(r_o < e_r){
				sum += r_o;
				now = 'o';
			} else {
				sum += e_r;
				now = 'e';
			}
		} else if(now == 'o'){
			if(r_o < o_e){
				sum += r_o;
				now = 'r';
			} else {
				sum += o_e;
				now = 'e';
			}
		} else {
			if(o_e < e_r){ 
				sum += o_e;
				now = 'o';
			} else {
				sum += e_r;
				now = 'r';
			}
		}
	}
	cout << sum << "\n";
	return 0;
}