#include <bits/stdc++.h>
using namespace std;

struct data{
	int h,w;
};


int main(){
	data snow,rock1,rock2;
	cin >> snow.w >> snow.h;
	cin >> rock1.w >> rock1.h;
	cin >> rock2.w >> rock2.h;

	if(rock2.h > rock1.h){
		data t = rock1;
		rock1 = rock2;
		rock2 = t;
	}

	bool past = 0;

	while(snow.h){
		snow.w += snow.h;
		if(!past && snow.h == rock1.h){
			past = 1;
			int jizz = snow.w - rock1.w; 
			if(jizz > 0) snow.w = jizz;
			else snow.w = 0;
		} else if(snow.h == rock2.h){
			int jizz = snow.w - rock2.w; 
			if(jizz > 0) snow.w = jizz;
			else snow.w = 0;
		}
		snow.h--;
	}

	cout << snow.w << "\n";

	return 0;
}