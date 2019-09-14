#include <bits/stdc++.h>
using namespace std;

int main(){
	int cnt = 0;
	for(long long i = 2;cnt < 10;++i){
		long long jizz = i * (i + 1) / 2;
		long long q = sqrt(jizz);
		if(q * q == jizz){
			printf("%10lld%10lld\n",q,i);
			cnt++;
		}
	}

	return 0;
}