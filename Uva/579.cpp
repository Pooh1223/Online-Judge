#include <bits/stdc++.h>
#define Pi acos(-1)
using namespace std;


int main(){
	string s;

	while(cin >> s){
		string tmp = "";
		int h,m;
		for(int i = 0;i < s.length();++i){
			if(s[i] != ':') tmp += s[i];
			else {
				h = stoi(tmp);
				tmp = "";
			}
		}
		m = stoi(tmp);
		if(!h && !m) break;
		
		if(h == 12) h = 0;
		double minus = abs((double)h / 6.0 * Pi + (double)m / 360.0 * Pi
		 - (double)m / 30.0 * Pi);
		double ans = min(minus * 180 / Pi,(2 * Pi - minus) * 180 / Pi);

		printf("%.3lf\n",ans);
	}

	return 0;
}