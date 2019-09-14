#include <bits/stdc++.h>
using namespace std;

int main(){
	int st,lk1,lk2,lk3;
	while(cin >> st >> lk1 >> lk2 >> lk3){
		if(!st && !lk1 && !lk2 && !lk3) break;
		int sum = 80;
		if(st - lk1 > 0) sum += st - lk1;
		else sum += 40 + st - lk1;
		sum += 40;
		if(lk2 - lk1 > 0) sum += lk2 - lk1;
		else sum += 40 + lk2 - lk1;
		if(lk2 - lk3 > 0) sum += lk2 - lk3;
		else sum += 40 + lk2 - lk3;
		cout << sum * 9 << "\n";
	}

	return 0;
}