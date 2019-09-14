#include <bits/stdc++.h>
using namespace std;

int main(){
	int h,d;
	float u,f;

	while(cin >> h >> u >> d >> f){
		if(!h) break;
		f /= 100.0 ;
		f *= u;
		float climb = 0;
		int day = 1;
		
		for(;climb <= h;++day){
			if(u > 0) climb += u;
			if(climb > h) break;
			u -= f;
			climb -= d;
			if(climb < 0) break;
		}
		if(climb < h) cout << "failure on day " << day << "\n";
		else cout << "success on day " << day << "\n";
	}



	return 0;
}