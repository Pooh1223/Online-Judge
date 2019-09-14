#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	long long n,m;
	while(cin >> n >> m){
		if(n == 0 && m == 0) break;
		if(m < n) swap(m,n);
		cout << m*n*(n+1)-n*(n+1)/2*(m+n)+n*(n+1)*(2*n+1)/6 << endl;
	}	
	return 0;
} 
