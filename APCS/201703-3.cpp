#include <bits/stdc++.h>
using namespace std;

int n,direct,l,r;
int a[55][55];

bool boom(int ck){
	if(ck < 0 || ck >= n) return 1;
	else return 0;
}
void left(int step){
	for(int i = r - 1; i <= r - step;--i){
		cout << a[l][r];
	}
	r -= step;
}
void up(int step){
	l -= step;
	cout << a[l][r];
}
void right(int step){
	r += step;
	cout << a[l][r];
}
void down(int step){
	l += step;
	cout << a[l][r];
}

int main(){
	
	cin >> n >> direct;
	for(int i = 0;i < n;++i){
		for(int j = 0;j < n;++j){
			cin >> a[i][j];
		}
	}
	l = n / 2;
	r = n / 2;
	cout << a[l][r];
	switch(direct){
		case 0:
			for(int i = 1;i <= n;++i){
				if(boom(l) || boom(r)) break;
				if(i % 2){
					left(i);
					up(i);
				} else {
					right(i);
					down(i);
				}
			}
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
	}

	return 0;
}