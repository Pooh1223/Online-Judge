#include <bits/stdc++.h>
using namespace std;

int mxDate[] = {31,29,31,30,31,30,31,31,30,31,30,31};

int toNum(char c){
	return c - '0';
}

string out(int u){
	if(u > 130) return "Check birth date";
	else return to_string(u);
}

int main(){

	int t;
	cin >> t;

	for(int tt = 1;tt <= t;++tt){
		cout << "Case #" << tt << ": ";

		string cur,bir;
		cin >> cur >> bir;
		if(cur == bir){
			cout << "0\n";
			continue;
		}

		int d1,d2,m1,m2,y1,y2; //1:current 2:birth

		d1 = toNum(cur[0]) * 10 + toNum(cur[1]);
		m1 = toNum(cur[3]) * 10 + toNum(cur[4]);
		y1 = toNum(cur[6]) * 1000 + toNum(cur[7]) * 100 + toNum(cur[8]) * 10 + toNum(cur[9]);
		d2 = toNum(bir[0]) * 10 + toNum(bir[1]);
		m2 = toNum(bir[3]) * 10 + toNum(bir[4]);
		y2 = toNum(bir[6]) * 1000 + toNum(bir[7]) * 100 + toNum(bir[8]) * 10 + toNum(bir[9]);

		if(y2 > y1){
			cout << "Invalid birth date\n";
		} else if(y2 == y1 && m2 > m1){
			cout << "Invalid birth date\n";
		} else if(y2 == y1 && m2 == m1 && d2 > d1){
			cout << "Invalid birth date\n";
		} else {
			if(y1 > y2){
				if(m1 > m2) cout << out(y1 - y2) << "\n";
				else if(m1 < m2) cout << out(y1 - y2 - 1) << "\n";
				else {
					if(d1 >= d2) cout << out(y1 - y2) << "\n";
					else cout << out(y1 - y2 - 1) << "\n";
				}
			} else {
				cout << "0\n";
			}
		}
	}

	return 0;
}