#include "lib1338.h"
#include <iostream>
#include <algorithm>
using namespace std;

int n,l,r;
long long c[1000005];
long long sparse[21][1000005],gg[21][1000005];

void table(){
	for(int i = 0;i < n;i++){
		sparse[0][i] = c[i];
		gg[0][i] = c[i];
	} 
	for(int y = 1;(1 << y) <= n;y++){
		for(int x = 0;x + (1 << y) <= n;x++){
			sparse[y][x] = min(sparse[y - 1][x],sparse[y - 1][x + (1 << (y - 1))]);
			gg[y][x] = __gcd(gg[y - 1][x],gg[y - 1][x + (1 << (y - 1))]);
		}
	}
} 

void init(int N, long long C[]){
	n = N;
	for(int i = 0;i < N;i++) c[i] = C[i];
	table();
}

int query(int L,int R){
	l = L + 1;
	r = R;
	int p = 31 - __builtin_clz(r - l + 1);
	return min(sparse[p][l - 1],sparse[p][r - (1 << p)]) == __gcd(gg[p][l - 1],gg[p][r - (1 << p)]);
}
